#include <bits/stdc++.h>
#include <vector>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int n = 0;
        cin >> n;
        vector<vector<int>> result(n, vector<int>(n, 0));
        if (n % 2 == 0) {
            int median = ceil(n / 2) - 1;
            result[median][median] = 0;
            result[median][median + 1] = 1;
            result[median + 1][median] = 2;
            result[median + 1][median + 1] = 3;
            for (int i = median - 1; i >= 0; i--) {
                int base = (median - i + 1) * 2;
                int counter = (base - 2) * (base - 2);
                // cout << "base: " << base << "\n";
                for (int j = i + 1; j < i + base; j++) {
                    result[i][j] = counter;
                    counter++;
                }
                for (int j = i + 1; j < i + base; j++) {
                    result[j][i + base - 1] = counter;
                    counter++;
                }
                for (int j = i + base - 2; j >= i; j--) {
                    result[i + base - 1][j] = counter;
                    counter++;
                }
                for (int j = i + base - 2; j >= i; j--) {
                    result[j][i] = counter;
                    counter++;
                }
            }
        } else {
            int median = ceil((float)n / 2) - 1;
            // cout << "median :" << median << "\n";
            result[median][median] = 0;
            for (int i = median - 1; i >= 0; i--) {
                int base = (median - i) * 2 + 1;
                int counter = (base - 2) * (base - 2);
                // cout << "base: " << base << "\n";
                for (int j = i + 1; j < i + base; j++) {
                    result[i][j] = counter;
                    counter++;
                }
                for (int j = i + 1; j < i + base; j++) {
                    result[j][i + base - 1] = counter;
                    counter++;
                }
                for (int j = i + base - 2; j >= i; j--) {
                    result[i + base - 1][j] = counter;
                    counter++;
                }
                for (int j = i + base - 2; j >= i; j--) {
                    result[j][i] = counter;
                    counter++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
