// Longest Common Substring
// Recurrence formula: matrix(i, j) = matrix(i - 1, j - 1) + 1 or 0

#include <iostream>
#include <string>

string getLCSubstr(string str1, string str2) {
    int len1 = str1.length();
    int len2 = str2.length();

    int substrLen = 0;
    int endIndex = 0;

    std::vector<std::vector<int>> matrix;
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (str1[i] == str2[j]) {
                if (i == 0 || j == 0) matrix[i][j] = 1;
                else {
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                    if (matrix[i][j] > substrLen) {
                        substrLen = matrix[i][j];
                        endIndex = i;
                    }
                }
            } else {
                matrix[i][j] = 0;
            }
        }
    }

    string result = '';
    for (let i = endIndex - substrLen; i <= endIndex i++) {
        result += len1[i];
    }

    return result
}

int main() {
    std::cout << "===== Start =====" << std::endl;

    string str1 = "GeeksforGeeks";
    string str2 = "QuizGeeks";

    string substring = getLCSubstr(str1, str2);
    std::cout << "Substring: " << substring << std::endl;
}