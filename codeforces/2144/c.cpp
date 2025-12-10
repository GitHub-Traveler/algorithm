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
        vector<int> a(n, 0);
        vector<int> b(n, 0);
        vector<int> dp(n, 0);
        dp[0] = 2;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        bool impossible = false;
        for (int i = 1; i < n; i++) {
            if (a[i] >= a[i - 1] &&
                a[i] >= b[i - 1] &&
                b[i] >= a[i - 1] &&
                b[i] >= b[i - 1]) {
                dp[i] = 2 * dp[i - 1];
            } else if ((a[i] < a[i - 1] &&
                        a[i] < b[i - 1]) ||
                       (b[i] < b[i - 1] &&
                        b[i] < a[i - 1])) {
                impossible = true;
                break;
            } else {
                dp[i] = dp[i - 1];
            }
            dp[i] = dp[i] % 998244353;
        }
        if (impossible) {
            cout << 0 << "\n";
        } else {
            cout << dp[n - 1] << "\n";
        }
    }
}
