#include <algorithm>
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
        i64 m = 0, n = 0;
        cin >> n >> m;
        vector<i64> a(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        i64 result = 0;
        if (m <= n) {
            for (int i = 1; i < m + 1; i++) {
                result += i * a[n - m + i - 1];
            }
        } else {
            i64 redundant = m - n;
            for (int i = 1; i < n + 1; i++) {
                result += (i + redundant) * a[i - 1];
            }
        }
        cout << result << "\n";
    }
}
