// Floyd Warshall Algorithm
// Recurrence formula: distance(i, j) = min(distance(i, j), distance(i, k) + distance(k, j))
// Time complexity: O(n^3)

#include <iostream>
#include <vector>

#define INF 1000000

void printMatrix(std::vector<std::vector<int>>& matrix) {
    for (auto row : matrix) {
        for (auto num : row) {
            std::cout << num << '\t';
        }

        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> floydWarshall(std::vector<std::vector<int>>& matrix, int n) {
    std::vector<std::vector<int>> result;
    for (auto row : matrix) {
        result.push_back(row);
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (result[i][k] + result[k][j] < result[i][j]) {
                    result[i][j] = result[i][k] + result[k][j];
                }
            }
        }
    }

    return result;
}

int main() {
    std::cout << "===== Start =====" << std::endl;

    std::vector<std::vector<int>> graph = {
        { 0, 5, INF, 8 },
        { 7, 0, 9, INF },
        { 2, INF, 0, 4 },
        { INF, INF, 3, 0 }
    };

    std::cout << "Graph: " << std::endl;
    printMatrix(graph);

    std::vector<std::vector<int>> result = floydWarshall(graph, graph.size());

    std::cout << "Result: " << std::endl;
    printMatrix(result);
}