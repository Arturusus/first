Пример работоспособного кода языке программирования Java:
import java.util.*;

public class Dijkstra {
    static class Edge {
        int to, weight;
        Edge(int to, int weight) { this.to = to; this.weight = weight; }
    }
    public static Map<Integer, Integer> dijkstra(List<List<Edge>> graph, int start) {
        int n = graph.size();
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.add(new int[]{0, start});
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int d = cur[0], u = cur[1];
            if (d > dist[u]) continue;
            for (Edge e : graph.get(u)) {
                if (dist[u] + e.weight < dist[e.to]) {
                    dist[e.to] = dist[u] + e.weight;
                    pq.add(new int[]{dist[e.to], e.to});
                }
            }
        }
        Map<Integer, Integer> res = new HashMap<>();
        for (int i = 0; i < n; i++) res.put(i, dist[i]);
        return res;
    }
    public static void main(String[] args) {
        List<List<Edge>> graph = new ArrayList<>();
        for (int i = 0; i < 6; i++) graph.add(new ArrayList<>());
        graph.get(0).add(new Edge(1, 4)); graph.get(0).add(new Edge(2, 7));
        graph.get(1).add(new Edge(0, 4)); graph.get(1).add(new Edge(3, 2)); graph.get(1).add(new Edge(4, 8));
        graph.get(2).add(new Edge(0, 7)); graph.get(2).add(new Edge(3, 2)); graph.get(2).add(new Edge(4, 5));
        graph.get(3).add(new Edge(1, 2)); graph.get(3).add(new Edge(2, 2)); graph.get(3).add(new Edge(4, 1)); graph.get(3).add(new Edge(5, 4));
        graph.get(4).add(new Edge(1, 8)); graph.get(4).add(new Edge(2, 5)); graph.get(4).add(new Edge(3, 1)); graph.get(4).add(new Edge(5, 11));
        graph.get(5).add(new Edge(3, 4)); graph.get(5).add(new Edge(4, 11));
        System.out.println("Расстояния от 0: " + dijkstra(graph, 0));
    }
}

Результат работы кода:
Расстояния от 0: {0=0, 1=4, 2=7, 3=6, 4=7, 5=10}
