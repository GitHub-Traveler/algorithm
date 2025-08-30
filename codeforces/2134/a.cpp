#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        i64 n = 0, a = 0, b = 0;
        cin >> n >> a >> b;
        if (a <= b) {
            if ((n - b) % 2 == 0) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        } else if (a > b) {
            if (((n - b) % 2 == 0) && ((n - a) % 2 == 0)) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
    }
}
