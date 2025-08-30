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
        int n = 0, k = 0;
        cin >> n >> k;
        vector<vector<int>> data(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++) {
            cin >> data[i][1] >> data[i][2] >> data[i][0];
        }
        sort(data.begin(), data.end());
        int current_coin = k;
        for (int i = 0; i < n; i++) {
            if (current_coin < data[i][0]) {
                if (data[i][1] <= current_coin && data[i][2] >= current_coin) {
                    current_coin = data[i][0];
                }
            }
        }
        cout << current_coin << "\n";
    }
}
