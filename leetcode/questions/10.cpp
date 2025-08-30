#include <iostream>
#include <string>
using namespace std;
class Solution {
  public:
    bool isMatch(string s, string p) {
        // 1. a = a
        // 2. a* = '', 'a', 'aa', ...
        // 3. .a = 2a, 3a, ... ?a
        // 4. .* = qwertafklqjahrdtgjln
        // dp[i][j] = dp[i - 1][j] if
        int size_s = s.length(), size_p = p.length();
        bool dp[size_s + 1][size_p + 1];
        int i, j, k;
        for (i = 0; i <= size_s; i++)
            for (int j = 0; j <= size_p; j++)
                dp[i][j] = false;

        // Initiate state 0 - 0
        dp[0][0] = true;
        // Initiate state 0 - n and n - 0
        for (j = 1; j <= size_p; j++)
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 2];
            else
                dp[0][j] = false;
        // Calculate the remaining slot in the DP array
        if (size_p >= 1 && size_s >= 1)
            for (i = 1; i <= size_s; i++)
                for (int j = 1; j <= size_p; j++)
                    if (p[j - 1] == '.') {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else if (p[j - 2] == '*') {
                        if (dp[i][j - 2])
                            dp[i][j] = dp[i][j - 2];
                        else if (dp[i - 1][j])
                            dp[i][j] = dp[i - 1][j] && (p[j - 2] == '.' ||
                                                        (p[j - 2] == s[i - 1]));
                        else
                            dp[i][j] = dp[i][j - 3];
                    } else {
                        dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1]);
                    }
        return dp[size_s][size_p];
    }
};

int main() {
    Solution test = Solution();
    cout << test.isMatch("aaa", "ab*a*c*a");
}
