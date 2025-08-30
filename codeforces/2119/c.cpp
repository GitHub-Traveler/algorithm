#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int msb_value(int n) {
    if (n == 0)
        return 0;
    int msb = 0;
    while (n != 0) {
        msb = n;
        n = n & (n - 1);
    }
    return msb;
}
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        i64 n = 0, l = 0, r = 0, k = 0;
        cin >> n >> l >> r >> k;
        if (n % 2 == 1) {
            cout << l << "\n";
            continue;
        }
        i64 and_max = l & r;
    }
}
