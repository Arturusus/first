Пример работоспособного кода на языке программирования Python:
import heapq

def dijkstra(graph, start):
    dist = {v: float('inf') for v in graph}
    dist[start] = 0
    pq = [(0, start)]
    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue
        for v, w in graph[u].items():
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                heapq.heappush(pq, (dist[v], v))
    return dist

graph = {
    'A': {'B': 4, 'C': 7},
    'B': {'A': 4, 'D': 2, 'E': 8},
    'C': {'A': 7, 'D': 2, 'E': 5},
    'D': {'B': 2, 'C': 2, 'E': 1, 'F': 4},
    'E': {'C': 5, 'D': 1, 'F': 11},
    'F': {'B': 8, 'D': 4, 'E': 11}
}
print("Расстояния от A:", dijkstra(graph, 'A'))

Результат работы программы:
Расстояния от A: {'A': 0, 'B': 4, 'C': 7, 'D': 6, 'E': 7, 'F': 10}
