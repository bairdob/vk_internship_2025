#include <fstream>
#include <iostream>
#include "graph.h"
#include "utils.h"

/**
 * @brief Загружает граф из текстового файла.
 * @param filepath Имя файла.
 * @return Graph Граф входных данных.
 * @throws std::runtime_error Если файл не открыт, формат данных некорректен или есть лишние данные.
 */
Graph parseFromFile(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file) {
        throw std::runtime_error("Не удалось открыть входной файл. Входной файл должен лежать рядом с бинарным файлом.");
    }

    int num_vertices, num_edges, start_vertex;

    if (!(file >> num_vertices >> num_edges) || num_vertices <= 0 || num_edges < 0) {
        throw std::runtime_error("Некорректный формат количества вершин или рёбер.");
    }

    std::vector<std::pair<int, int>> edges;
    for (size_t i = 0; i < num_edges; ++i) {
        int u, v;
        if (!(file >> u >> v)) {
            throw std::runtime_error("Недостаточно данных для рёбер.");
        }
        edges.emplace_back(u, v);
    }

    if (!(file >> start_vertex) || start_vertex < 0 || start_vertex >= num_vertices) {
        throw std::runtime_error("Некорректная стартовая вершина.");
    }

    std::string extra;
    if (file >> extra) {
        throw std::runtime_error("Файл содержит лишние данные.");
    }

    return Graph(num_vertices, num_edges, edges, start_vertex);
}
