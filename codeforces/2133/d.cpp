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
        vector<i64> h(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        vector<i64> dp(n + 1, 0);
        for (int i = 1; i < n + 1; i++) {
            if (i == 1) {
                dp[i] = h[i - 1];
            } else {
                dp[i] = min(dp[i - 2] + h[i - 2] + max(h[i - 1] - (i - 1), 0ll), dp[i - 1] + h[i - 1] - 1);
            }
        }
        cout << dp[n] << "\n";
    }
}
