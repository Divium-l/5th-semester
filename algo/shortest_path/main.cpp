#include <iostream>
#include <random>
#include <vector>
#include <iomanip>

const int MAX = 10;
const int MIN = 1;
const int WIDTH = 3;

uint32_t rnd();
void randomizeGraph(std::vector<std::vector<uint32_t>> &graph);
void printGraph(std::vector<std::vector<uint32_t>> &graph);
uint32_t findMinPath(std::vector<std::vector<uint32_t>> &graph, const size_t a, const size_t b);

int main() { 

    size_t size;
    std::cout << "Input number of points: ";
    std::cin >> size;

    std::vector<std::vector<uint32_t>> graph(size, std::vector<uint32_t>(size));

    randomizeGraph(graph);
    printGraph(graph);
    
    size_t point_1, point_2;
    std::cout << "Input start and end point" << std::endl;
    std::cin >> point_1 >> point_2;

    std::cout << "Shortest path: " << findMinPath(graph, point_1, point_2) << std::endl;

    return 0;
}

uint32_t rnd() {
	std::random_device rd;     
	std::mt19937 rng(rd());    
	std::uniform_int_distribution<uint16_t> uni(MIN, MAX);

	return uni(rng);
}

void randomizeGraph(std::vector<std::vector<uint32_t>> &graph) {
    for (size_t i = 0; i < graph.size(); i++)
        for (size_t j = i; j < graph.size(); j++)
            if (i == j) 
                graph[i][j] = 0;
            else {
                graph[i][j] = rnd();
                graph[j][i] = graph[i][j];
            }
}

void printGraph(std::vector<std::vector<uint32_t>> &graph) {
    std::cout << "Graph:" << std::endl;
    for (size_t i = 0; i < graph.size(); i++) {
        std::cout << i + 1 << ": ";
        for (size_t j = 0; j < graph.size(); j++) {
            std::cout << std::setw(WIDTH) << graph[i][j];
        }
        std::cout << std::endl;
    }
}

uint32_t findMinPath(std::vector<std::vector<uint32_t>> &graph, const size_t point_1, const size_t point_2) {
    auto minPath = graph;

    for (size_t k = 0; k < graph.size(); k++)
        for (size_t i = 0; i < graph.size(); i++)
            for (size_t j = 0; j < graph.size(); j++)
                if (minPath[i][k] + minPath[k][j] < minPath[i][j])
                    minPath[i][j] = minPath[i][k] + minPath[k][j];

    return minPath[point_1 - 1][point_2 - 1];
}
