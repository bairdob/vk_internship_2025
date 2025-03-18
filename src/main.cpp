#include <iostream>

#include "graph.h"
#include "utils.h"


int main(){
    try {
        Graph graph = parseFromFile("graph.txt");
        std::vector<int> distances = graph.findShortestPaths();

        for (auto dist : distances){
            std::cout << dist << "\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
