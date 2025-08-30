#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    unsigned int availableCell(unsigned int n, unsigned int i) {
        if (n % 2) {
            if (i < n / 2) {
                return i + 1;
            } else {
                return n / 2 - (i - n / 2);
            }
        } else {
            if (i < n / 2) {
                return i + 1;
            } else {
                return n / 2 - (i - n / 2) - 1;
            }
        }
    }

    int maxCollectedFruit(vector<vector<int>>& fruits) {
        unsigned int result = 0;
        unsigned int matrix_size = fruits.size();
        vector<vector<unsigned int>> dp(matrix_size,
                                        vector<unsigned int>(matrix_size));
        unsigned int agentBot = fruits[matrix_size - 1][0],
                     agentMid = fruits[0][0],
                     agentTop = fruits[0][matrix_size - 1];
        dp[0][0] = agentMid;
        dp[0][matrix_size - 1] = agentTop;
        dp[matrix_size - 1][0] = agentBot;
        cout << matrix_size;

        for (unsigned int i = 1; i < matrix_size; i++) {
            dp[i][i] += fruits[i][i] + dp[i - 1][i - 1];
            unsigned int available_cell = availableCell(matrix_size, i);
            for (unsigned int j = 0; j < available_cell; j++) {
                unsigned int temp = matrix_size - 1 - j;
                if (i == matrix_size) {
                    continue;
                } else if (j == 0) {
                    dp[i][temp] = max(dp[i - 1][temp], dp[i - 1][temp - 1]) +
                                  fruits[i][temp];
                    dp[temp][i] = max(dp[temp][i - 1], dp[temp - 1][i - 1]) +
                                  fruits[temp][i];
                } else {
                    dp[i][temp] =
                        max(dp[i - 1][temp + 1],
                            max(dp[i - 1][temp], dp[i - 1][temp - 1])) +
                        fruits[i][temp];
                    dp[temp][i] =
                        max(dp[temp - 1][i - 1],
                            max(dp[temp][i - 1], dp[temp + 1][i - 1])) +
                        fruits[temp][i];
                }
            }
        }
        agentBot = dp[matrix_size - 1][matrix_size - 2];
        agentTop = dp[matrix_size - 2][matrix_size - 1];
        agentMid = dp[matrix_size - 1][matrix_size - 1];
        result = agentBot + agentMid + agentTop;
        return result;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    vector<vector<int>> test_input = {
        {1, 2, 3, 4}, {5, 6, 8, 7}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    cout << sol.maxCollectedFruit(test_input) << endl;
    return 0;
}