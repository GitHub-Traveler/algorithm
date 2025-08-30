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
        vector<i64> a(n, 0), b(n, 0), c(n, 0), d(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i] >> c[i] >> d[i];
        }
        i64 num_exchange = 0;
        for (int i = 0; i < n; i++) {
            i64 current_num_exchange = 0;
            if (a[i] <= c[i]) {
                if (b[i] > d[i]) {
                    current_num_exchange += (a[i] + (b[i] - d[i]));
                }
                // continue;
            }
            if (a[i] > c[i]) {
                current_num_exchange += (a[i] - c[i]);
                if (b[i] > d[i]) {
                    current_num_exchange += c[i] + (b[i] - d[i]);
                }
                // continue;
            }
            num_exchange += (i64)current_num_exchange;
        }
        cout << num_exchange << "\n";
    }
}
