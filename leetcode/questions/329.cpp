#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[200][200];
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int i,j;
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                dp[i][j] = -1;
        int max_length = 0;
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++) {
                max_length = max(max_length, helper(matrix, i, j));
            }
        return max_length;
    }

    int helper(vector<vector<int>>& matrix, int i, int j) {
        if (dp[i][j] != -1)
            return dp[i][j];
        bool direction[4] = {false, false, false, false};
        if (i > 0) direction[0] = true;
        if (i < matrix.size() - 1) direction[1] = true;
        if (j > 0) direction[2] = true;
        if (j < matrix[0].size() - 1) direction[3] = true;
        int max_length = 1;
        if (direction[0]) 
            max_length = max((matrix[i][j] < matrix[i - 1][j])?(helper(matrix, i - 1, j) + 1):1, max_length);
        if (direction[1]) 
            max_length = max((matrix[i][j] < matrix[i + 1][j])?(helper(matrix, i + 1, j) + 1):1, max_length);
        if (direction[2]) 
            max_length = max((matrix[i][j] < matrix[i][j - 1])?(helper(matrix, i, j - 1) + 1):1, max_length);
        if (direction[3]) 
            max_length = max((matrix[i][j] < matrix[i][j + 1])?(helper(matrix, i, j + 1) + 1):1, max_length);
        return dp[i][j] = max_length;
    }
};