// Edit Distance Problem
// Recurrence formula: result[i][j] = min( result[i - 1][j] + Deletion, result[i][j - 1] + Insertion, result[i][j] + 0 or Change )
// Time complexity: O(nm) (n: Length of str1, m: Length of str2)

using namespace std;

int min(int num1, int num2, int num3) {
    if (num1 <= num2 && num1 <= num3) {
        return num1;
    } else if (num2 < num1 && num2 < num3) {
        return num2;
    } else {
        return num3;
    }
}

// n: Length of str1, m: Length of str2
int getEditDist(string str1, string str2, int n, int m, int deletionCost, int insertionCost, int changeCost) {
    int result[n + 1][m + 1];

    result[0][0] = 0;
    for (int i = 1; i < n + 1; i++) {
        result[i][0] = result[i - 1][0] + deletionCost;
    }

    for (int j = 0; j < m + 1; j++) {
        result[0][j] = result[0][j - 1] + insertionCost;
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            int currentChangeCost = (X[i] == Y[i]) ? 0 : changeCost
            result[i][j] = min(result[i - 1][j] + deletionCost, result[i][j - 1] + insertionCost, result[i - 1][j - 1] + currentChangeCost);
        }
    }
}

int main() {
    cout << "===== Start =====" << endl;

    string str1 = "sunday";
    string str2 = "saturday";

    cout << getEditDist(str1, str2, str1.length(), str2.length()) << endl;
}
