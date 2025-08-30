#include <bits/stdc++.h>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> result_mat(m, vector<int>(n, 0));
        stack<pair<int, int>> stk;
        vector<int> heights(n, 0);
        for (int i = 0; i < m; i++) {
            stk = stack<pair<int, int>>();
            for (int j = 0; j < n; j++) {
                heights[j] = (mat[i][j] == 0) ? 0 : (heights[j] + 1);
            }
            for (int j = 0; j < n; j++) {

                int left_boundary = -1;
                while (!stk.empty()) {
                    if (stk.top().second >= heights[j])
                        stk.pop();
                    else {
                        left_boundary = stk.top().first;
                        break;
                    }
                }
                if (left_boundary != -1) {
                    result_mat[i][j] += result_mat[i][left_boundary];
                }
                result_mat[i][j] += heights[j] * (j - left_boundary);
                cout << i << " " << j << " " << result_mat[i][j] << "\n";
                cout << "debug: " << left_boundary << " " << heights[j] << "\n";
                stk.emplace(j, heights[j]);
            }
        }
        int final_result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                final_result += result_mat[i][j];
            }
        }
        return final_result;
    }
};