#include "graph.h"

/**
 * @brief Конструктор класса Graph.
 *
 * @param vertices Количество вершин в графе.
 * @param edges_count Количество рёбер в графе.
 * @param edge_list Список рёбер графа (пары вершин).
 * @param start Стартовая вершина для алгоритмов поиска.
 */
Graph::Graph(const int &vertices, const int &edges_count, const std::vector<std::pair<int, int>> &edge_list, const int &start)
    : num_vertices(vertices), num_edges(edges_count), edges(std::move(edge_list)), start_vertex(start) {
    build_adjacency_list();
}

/**
 * @brief Создает список смежности.
 */
void Graph::build_adjacency_list() noexcept {
    for (auto [u, v] : edges) {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
}

/**
 * @brief Перегруженный оператор вывода графа в поток.
 * @param os Поток вывода.
 * @param graph Граф.
 * @return Поток вывода с информацией о графе.
 */
std::ostream &operator<<(std::ostream &os, const Graph &graph) noexcept {
    os << "Граф с " << graph.num_vertices << " вершинами и " << graph.num_edges << " ребрами\n";
    os << "Ребра:\n";
    for (const auto &[u, v] : graph.edges) {
        os << u << " - " << v << "\n";
    }
    os << "Список смежности:\n";
    for (const auto &[vertex, neighbors] : graph.adj_list) {
        os << vertex << ": ";
        for (int neighbor : neighbors) {
            os << neighbor << " ";
        }
        os << "\n";
    }
    return os;
}

/**
 * @brief Алгоритм поиска кратчайших путей в графе (BFS).
 * @return Вектор расстояний от стартовой вершины до всех остальных.
 */
std::vector<int> Graph::findShortestPaths() noexcept {
    std::vector<int> distance(num_vertices, -1);
    std::queue<int> q;

    distance[start_vertex] = 0;
    q.push(start_vertex);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj_list[node]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[node] + edge_length;
                q.push(neighbor);
            }
        }
    }

    return distance;
}
