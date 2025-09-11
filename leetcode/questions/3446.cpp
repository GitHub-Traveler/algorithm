#include <bits/stdc++.h>
#include <vector>
using namespace std;

class solution {
public:
    vector<vector<int>> sortmatrix(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<vector<int>> result(n, vector<int>(n));
        for (int i = 0; i < 2 * n - 1; i++) {
            int length = n - abs(n - 1 - i);
            vector<int> temp_arr(length, 0);
            int init_x = 0;
            int init_y = 0;
            if (i < n) {
                init_x = (n - 1) - i;
                init_y = 0;
            } else {
                init_x = 0;
                init_y = i - (n - 1);
            }
            for (int j = 0; j < length; j++) {
                temp_arr[j] = grid[init_x + j][init_y + j];
            }
            if (i < n) {
                sort(temp_arr.begin(), temp_arr.end(), greater<int>());
            } else {
                sort(temp_arr.begin(), temp_arr.end());
            }
            for (int j = 0; j < length; j++) {
                result[init_x + j][init_y + j] = temp_arr[j];
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    solution s;
    vector<vector<int>> nums = {{2, 2, 1, 2, 2}, {2, 0, 2, 2, 0}, {2, 0, 1, 1, 0}, {1, 0, 2, 2, 2}, {2, 0, 0, 2, 2}};
    vector<vector<int>> result = s.sortmatrix(nums);
    return 0;
}
