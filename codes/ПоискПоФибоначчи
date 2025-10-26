Рабочий код на языке программирования Python:

def fibonacci_search(arr, target):
    # Генерируем ряд Фибоначчи, пока не найдется число, большее или равное длине массива
    fibM_minus_2 = 0  # F(m-2)
    fibM_minus_1 = 1  # F(m-1)
    fibM = fibM_minus_1 + fibM_minus_2  # F(m)

    while fibM < len(arr):
        fibM_minus_2 = fibM_minus_1
        fibM_minus_1 = fibM
        fibM = fibM_minus_1 + fibM_minus_2

    offset = -1  # Начало поиска

    # Главное тело поиска
    while fibM > 1:
        # Индекс потенциального элемента
        i = min(offset + fibM_minus_2, len(arr)-1)

        # Если элемент меньше целевого, идем вправо
        if arr[i] < target:
            fibM = fibM_minus_1
            fibM_minus_1 = fibM_minus_2
            fibM_minus_2 = fibM - fibM_minus_1
            offset = i

        # Если элемент больше целевого, идем влево
        elif arr[i] > target:
            fibM = fibM_minus_2
            fibM_minus_1 = fibM_minus_1 - fibM_minus_2
            fibM_minus_2 = fibM - fibM_minus_1

        # Если элемент найден, возвращаем его индекс
        else:
            return i

    # Дополнительно проверяем последний элемент
    if fibM_minus_1 and arr[offset+1] == target:
        return offset + 1

    # Если элемент не найден, возвращаем -1
    return -1

# Пример использования
if __name__ == "__main__":
    sorted_data = [10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100]
    target_value = 85
    result = fibonacci_search(sorted_data, target_value)

    if result != -1:
        print(f"Элемент {target_value} найден на позиции {result}")
    else:
        print(f"Элемент {target_value} не найден")


Результат работы программы:
Значение 21 найдено на позиции 4
