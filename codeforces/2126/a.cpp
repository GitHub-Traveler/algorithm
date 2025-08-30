#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int x = 0;
        int result = 9;
        cin >> x;
        if (!x) {
            cout << 0 << "\n";
            continue;
        }
        while (x) {
            int rem = x % 10;
            x /= 10;
            result = min(result, rem);
        }
        cout << result << "\n";
    }
}
