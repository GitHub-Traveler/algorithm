#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i < n; i++) {
            dp[0][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = 1 + max(max(dp[i][j], dp[i + 1][j]), dp[i][j + 1]);
                } else {
                    dp[i + 1][j + 1] = max(max(dp[i][j], dp[i + 1][j]), dp[i][j + 1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    string text1 = "abcde";
    string text2 = "ace";
    cout << sol.longestCommonSubsequence(text1, text2) << endl;
    return 0;
}