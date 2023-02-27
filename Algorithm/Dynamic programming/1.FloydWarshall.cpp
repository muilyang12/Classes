// Floyd Warshall Algorithm
// Recurrence formula: distance(i, j) = min(distance(i, j), distance(i, k) + distance(k, j))

#include <iostream>
#include <vector>

#define INF 1000000

void printMatrix(std::vector<std::vector<int>>& matrix) {
    for (auto row : matrix) {
        for (auto num : row) {
            std::cout << num << ' ';
        }

        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> floydWarshall(std::vector<std::vector<int>>& matrix, int n) {
    std::vector<std::vector<int>> result;

    for (auto row : result) {
        std::vector<int> arr;

        for (auto num : row) {
            arr.push_back(num);
        }

        result.push_back(arr);
    }

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            for (let k = 0; k < n; k++) {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                    result[i][j] = 1;
                } else {
                    result[i][j] = matrix[i][j];
                }
            }
        }
    }

    return result;
}

int main() {
    std::cout << "===== Start =====" << std::endl;

    std::vector<std::vector<int>> graph = { 
        { 0, 4, 2, INF },
        { INF, 0, 5, INF },
        { INF, -1, 0, INF },
        { 3, INF, INF, 0 }
    };

    std::cout << "Graph: " << std::endl;
    printMatrix(graph);

    std::vector<std::vector<int>> result = floydWarshall(graph, graph.size());

    std::cout << "Result: " << std::endl;
    printMatrix(result);
}