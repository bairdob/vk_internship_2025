#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <unordered_map>

class Graph {
    int num_vertices; // Количество вершин
    int num_edges; // Количество рёбер
    std::vector<std::pair<int, int>> edges; // Список рёбер
    int start_vertex; // Начальная вершина
    int edge_length{1}; // длина ребра
    std::unordered_map<int, std::vector<int>> adj_list; // Список смежности

    void build_adjacency_list() noexcept;

public:
    Graph(const int &, const int &, const std::vector<std::pair<int, int>> &, const int &);

    std::vector<int> findShortestPaths() noexcept;
    friend std::ostream &operator<<(std::ostream &os, const Graph &graph) noexcept;
};

#endif // GRAPH_H
