#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int a = 0, b = 0;
        cin >> a >> b;
        if (a == b) {
            cout << 0 << "\n";
        } else if ((a % b == 0) || (b % a == 0)) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    }
}
