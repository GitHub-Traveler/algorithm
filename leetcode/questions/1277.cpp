#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int max_square = min(m, n);
        int counter = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if (matrix[0][0]) {
            dp[0][0] = 1;
            counter++;
        }
        for (int i = 1; i < m; i++) {
            if (matrix[i][0]) {
                dp[i][0] = 1;
                counter++;
            }
        }
        for (int j = 1; j < n; j++) {
            if (matrix[0][j]) {
                dp[0][j] = 1;
                counter++;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
                }
                counter += dp[i][j];
            }
        }
        return counter;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    vector<vector<int>> test = {{1, 1}, {1, 1}};
    cout << sol.countSquares(test) << "\n";
    return 0;
}
