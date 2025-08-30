#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int n = 0, m = 0, p = 0, q = 0;
        cin >> n >> m >> p >> q;
        if (((n % p) == 0) && ((n / p) * q != m))
            cout << "NO" << "\n";
        else
            cout << "YES" << "\n";
    }
}
