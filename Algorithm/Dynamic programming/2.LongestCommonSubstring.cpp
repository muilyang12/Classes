// Longest Common Substring
// Recurrence formula: matrix(i, j) = matrix(i - 1, j - 1) + 1 or 0

#include <iostream>
#include <vector>

using namespace std;

string getLCSubstr(string str1, string str2) {
    int len1 = str1.length();
    int len2 = str2.length();

    int substrLen = 0;
    int endIndex = 0;

    vector<vector<int>> matrix(len1, vector<int>(len2, 0));
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
            }
        }
    }

    string result = "";
    for (int i = (endIndex + 1) - substrLen; i <= endIndex; i++) {
        result += str1[i];
    }

    return result;
}

int main() {
    cout << "===== Start =====" << endl;

    string str1 = "MooreHello";
    string str2 = "HiMoore";
    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;

    string substring = getLCSubstr(str1, str2);
    cout << "Substring: " << substring << endl;
}