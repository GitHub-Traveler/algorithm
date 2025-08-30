#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // Each cell in the dungeon is associated with a value (least health to get to the princess from there)
        int m = dungeon.size(), n = dungeon[0].size();
        int dp[m][n];
        dp[m-1][n-1] = max(0, - dungeon[m-1][n - 1]);
        
        int i,j;
        for (i = m - 2;i >= 0; i--)
            dp[i][n - 1] = max(dp[i + 1][n - 1] - dungeon[i][n - 1], 0);

        for (j = n - 2;j >=0; j--)
            dp[m - 1][j] = max(dp[m - 1][j + 1] - dungeon[m - 1][j], 0);

        for (i = m - 2;i >= 0; i--)
            for (j = n - 2;j >=0; j--) {
                dp[i][j] = min(max(dp[i][j + 1] - dungeon[i][j], 0), max(dp[i + 1][j] - dungeon[i][j], 0));
            }
        return dp[0][0] + 1;
    }
};

int main() {
    Solution test = Solution();
    vector<vector<int>> dungeon = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    cout << test.calculateMinimumHP(dungeon);
}