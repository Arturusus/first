from fastapi import FastAPI, Query
from fastapi.middleware.cors import CORSMiddleware
import pandas as pd
from pathlib import Path

BASE = Path(__file__).resolve().parent
DATA = BASE / "data"

fighters_df = pd.read_csv(DATA / "fighters.csv")
fights_df = pd.read_csv(DATA / "Fights.csv")

# Нормализуем имена (на всякий случай пробелы)
fighters_df["Full Name"] = fighters_df["Full Name"].astype(str).str.strip()
fights_df["Fighter1"] = fights_df["Fighter1"].astype(str).str.strip()
fights_df["Fighter2"] = fights_df["Fighter2"].astype(str).str.strip()

app = FastAPI(title="UFC Web API")

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],   # для разработки ок, потом ограничишь доменом
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

def find_fight_row(a: str, b: str):
    """Возвращает строку боя (Series) или None."""
    mask = ((fights_df["Fighter1"] == a) & (fights_df["Fighter2"] == b)) | \
           ((fights_df["Fighter1"] == b) & (fights_df["Fighter2"] == a))
    rows = fights_df[mask]
    if rows.empty:
        return None
    return rows.iloc[0]

def get_fighter(name: str):
    row = fighters_df[fighters_df["Full Name"] == name]
    if row.empty:
        return None
    r = row.iloc[0].to_dict()
    # приводим NaN к None
    return {k: (None if pd.isna(v) else v) for k, v in r.items()}

@app.get("/fighters")
def list_fighters():
    names = fighters_df["Full Name"].dropna().astype(str).tolist()
    names.sort()
    return {"fighters": names}

@app.get("/fighter")
def fighter(name: str = Query(...)):
    f = get_fighter(name)
    if not f:
        return {"found": False}
    return {"found": True, "fighter": f}

@app.get("/history")
def history(a: str = Query(...), b: str = Query(...)):
    row = find_fight_row(a, b)
    if row is None:
        return {"has_fight": False}

    # кто победил в этом бою (по датасету)
    # В Fights.csv есть Result1/Result2, где обычно "W/L/D/NC" и т.п. [file:2]
    r1 = str(row.get("Result1", "")).strip()
    r2 = str(row.get("Result2", "")).strip()

    winner = None
    if r1 == "W" and r2 == "L":
        winner = row["Fighter1"]
    elif r2 == "W" and r1 == "L":
        winner = row["Fighter2"]

    return {
        "has_fight": True,
        "fight": {
            "fighter1": row["Fighter1"],
            "fighter2": row["Fighter2"],
            "result1": r1,
            "result2": r2,
            "winner": winner,
            "method": None if pd.isna(row.get("Method")) else row.get("Method"),
            "round": None if pd.isna(row.get("Round")) else row.get("Round"),
        }
    }

@app.post("/predict")
def predict(payload: dict):
    """
    Заглушка предсказания.
    Потом сюда вставишь свой код модели/ML.
    Сейчас: простое правило — кто тяжелее (Wt.), тот "победит".
    """
    a = payload.get("a")
    b = payload.get("b")
    fa = get_fighter(a)
    fb = get_fighter(b)
    if not fa or not fb:
        return {"ok": False, "error": "Unknown fighter name"}

    wa = fa.get("Wt.")
    wb = fb.get("Wt.")
    if wa is None or wb is None:
        winner = a  # fallback
    else:
        winner = a if float(wa) >= float(wb) else b

    return {
        "ok": True,
        "winner": winner,
        "meta": {
            "explain": "TEMP RULE: higher weight wins",
            "a_wt": wa,
            "b_wt": wb,
        }
    }
