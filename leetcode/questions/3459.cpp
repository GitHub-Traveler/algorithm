#include <vector>
using namespace std;

class Solution {
public:
    const int DDICT[4][2] = {{1, -1}, {-1, -1}, {-1, 1}, {1, 1}};
    int dfs(int x, int y, int direction, vector<vector<vector<vector<int>>>> &chain, vector<vector<int>> &grid,
            bool turn, int current) {
        int n = chain.size();
        int m = chain[0].size();
        if (x < 0 || y < 0 || x >= n || y >= m) {
            return 0;
        }
        if (grid[x][y] != current) {
            return 0;
        }
        if (chain[x][y][direction][turn] != -1) {
            return chain[x][y][direction][turn];
        }
        int new_x = DDICT[direction][0] - x;
        int new_y = DDICT[direction][1] - y;
        int maxR = 1 + dfs(new_x, new_y, direction, chain, grid, turn, 2 - current);
        chain[x][y][direction][turn] = maxR;
        if (turn) {
            int new_direction = (direction + 1) % 4;
            maxR = max(maxR, dfs(x, y, new_direction, chain, grid, false, current));
        }
        return maxR + 1;
    }
    int lenOfVDiagonal(vector<vector<int>> &grid) {

        int n = grid.size();
        int m = grid[0].size();
        int result = 0;
        vector<vector<vector<vector<int>>>> chain(
            n, vector<vector<vector<int>>>(m, vector<vector<int>>(4, vector<int>(2, -1))));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        result = max(result, dfs(i + DDICT[d][0], j + DDICT[d][1], d, chain, grid, true, 2) + 1);
                    }
                }
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> nums = {{2, 2, 1, 2, 2}, {2, 0, 2, 2, 0}, {2, 0, 1, 1, 0}, {1, 0, 2, 2, 2}, {2, 0, 0, 2, 2}};
    int result = s.lenOfVDiagonal(nums);
    return 0;
}
