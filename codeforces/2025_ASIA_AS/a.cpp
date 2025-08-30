#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int a = 0; a < t; a++) {
        int r, c;
        cin >> r >> c;
        vector<vector<long long>> layout(r, vector<long long>(c));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                char temp;
                cin >> temp;
                if (temp == '#') {
                    layout[i][j] = 0;
                } else {
                    layout[i][j] = 1;
                }
            }
        }

        vector<vector<vector<long long>>> dp(4, vector<vector<long long>>(r, vector<long long>(c, 0)));
        vector<vector<long long>> sum_row(4, vector<long long>(r, 0));
        vector<vector<long long>> sum_col(4, vector<long long>(c, 0));
        for (int a = 0; a < 4; a++) {
            if (a == 0) {
                dp[a] = layout;
            } else {
                for (int i = 0; i < r; ++i) {
                    for (int j = 0; j < c; ++j) {
                        if (layout[i][j]) {
                            dp[a][i][j] = sum_row[a - 1][i] + sum_col[a - 1][j] - 2 * dp[a - 1][i][j];
                        } else {
                            dp[a][i][j] = 0;
                        }
                    }
                }
            }
            if (a == 4) {
                break;
            }
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    sum_row[a][i] += dp[a][i][j];
                    sum_col[a][j] += dp[a][i][j];
                }
            }
        }
        int total = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                // cout << i << j << endl;
                // cout << "here" << endl;
                dp[3][i][j] = dp[3][i][j] - dp[2][i][j] * 2 + dp[1][i][j];
                // cout << "here" << endl;
                total += dp[3][i][j];
            }
        }
        for (int i = 0; i < r; i++) {
            total -= sum_row[0][i] * (sum_row[0][i] - 1) * (sum_row[0][i] - 2);
        }
        for (int j = 0; j < c; j++) {
            total -= sum_col[0][j] * (sum_col[0][j] - 1) * (sum_col[0][j] - 2);
        }
        cout << total << endl;
    }
}
