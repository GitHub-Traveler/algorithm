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
        vector<int> g(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> g[i];
        }
        sort(g.begin(), g.end());
        i64 result = 0;
        if (n % 2) {
            result += g[0];
            for (int i = 2; i < n; i += 2) {
                result += g[i];
            }
        } else {
            for (int i = 1; i < n; i += 2) {
                result += g[i];
            }
        }
        cout << result << "\n";
    }
}
