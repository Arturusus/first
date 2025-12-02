Пример работоспособного кода на языке программирования C++:
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

std::vector<int> dijkstra(const std::vector<std::vector<std::pair<int, int>>>& graph, int start) {
    int n = graph.size();
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    dist[start] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int n = 6;
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    graph[0] = {{1, 4}, {2, 7}};
    graph[1] = {{0, 4}, {3, 2}, {4, 8}};
    graph[2] = {{0, 7}, {3, 2}, {4, 5}};
    graph[3] = {{1, 2}, {2, 2}, {4, 1}, {5, 4}};
    graph[4] = {{1, 8}, {2, 5}, {3, 1}, {5, 11}};
    graph[5] = {{3, 4}, {4, 11}};
    auto dist = dijkstra(graph, 0);
    std::cout << "Rast ot 0: ";
    for (int d : dist) std::cout << d << " ";
    std::cout << std::endl;
    return 0;
}

Результат работы программы:
Rast ot 0: 0 4 7 6 7 10
