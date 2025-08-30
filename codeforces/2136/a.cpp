#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int a = 0, b = 0, c = 0, d = 0;
        cin >> a >> b >> c >> d;
        int e = c - a, f = d - b;
        if ((2 * a + 2) >= b && (2 * b + 2) >= a && (2 * e + 2) >= f && (2 * f + 2) >= e) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}
