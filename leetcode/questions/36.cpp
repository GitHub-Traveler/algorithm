#include <bits/stdc++.h>
#include <vector>
using namespace std;
using i64 = long long;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<vector<bool>> exist_box(9, vector<bool>(9, false));
        vector<vector<bool>> exist_col(9, vector<bool>(9, false));
        vector<vector<bool>> exist_row(9, vector<bool>(9, false));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int current = (int)(board[i][j] - '1');
                int current_box = (i / 3) * 3 + (j / 3);
                if (exist_box[current_box][current] || exist_col[j][current] || exist_row[i][current]) {
                    return false;
                } else {
                    exist_box[current_box][current] = true;
                    exist_col[j][current] = true;
                    exist_row[i][current] = true;
                }
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    int n = 10, m = 15;
    long long result = s.flowerGame(n, m);
    return 0;
}