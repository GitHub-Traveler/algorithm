#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        unsigned int dp[n+1][m+1];

        dp[0][0] = 1;
        int i, j;
        for (i = 1; i <= n; i++)
            dp[i][0] = 1;
        for (j = 1; j <= m; j++)
            dp[0][j] = 0;
        
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                dp[i][j] = (s[i - 1] == t[j - 1])?(dp[i - 1][j - 1] + dp[i - 1][j]):(dp[i - 1][j]);
        return dp[n][m];
    }
};

int main() {
    Solution test = Solution();
    cout << test.numDistinct("aaaaaaa", "aaabaaa");
}


