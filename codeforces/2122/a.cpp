#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int n = 0, m = 0;
        cin >> n >> m;
        if (n < 2 || m < 2) {
            cout << "NO" << "\n";
            continue;
        }
        if (n == 2 && m == 2) {
            cout << "NO" << "\n";
            continue;
        }
        cout << "YES" << "\n";
        continue;
    }
}
