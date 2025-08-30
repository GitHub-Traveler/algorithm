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
        vector<int> blockPos(n, -1);
        unordered_map<int, vector<int>> hashMap;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        };
        for (int i = 0; i < n; i++) {
            if (hashMap.find(a[i]) == hashMap.end()) {
                hashMap[a[i]] = vector<int>(1, i);
            } else {
                hashMap[a[i]].emplace_back(i);
            }
            if (hashMap[a[i]].size() >= a[i]) {
                blockPos[i] = hashMap[a[i]][hashMap[a[i]].size() - a[i]];
            }
        }
        vector<int> dp(n + 1, 0);
        for (int i = 1; i < n + 1; i++) {
            if (blockPos[i - 1] != -1) {
                // cout << "!";
                dp[i] = max(dp[i - 1], dp[blockPos[i - 1]] + a[i - 1]);
            } else {
                dp[i] = dp[i - 1];
            }
        }
        // cout << "debug: ";
        // for (int i = 0; i < n; i++) {
        //     cout << blockPos[i] << " ";
        // }
        // cout << "\n";
        // cout << "dp:";
        // for (int i = 0; i < n + 1; i++) {
        //     cout << dp[i] << " ";
        // }
        //
        // cout << "\n";
        cout << dp[n] << "\n";
    }
}
