#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int a = 0;
        int b = 0;
        int x = 0;
        int y = 0;
        cin >> a >> b >> x >> y;
        if (a > b) {
            if (a - b > 1) {
                cout << -1 << "\n";
                continue;
            } else if (a - b == 1) {
                if (a % 2 == 1) {
                    cout << y << "\n";
                    continue;
                } else {
                    cout << -1 << "\n";
                    continue;
                }
            }
        }
        if (a == b) {
            cout << 0 << "\n";
            continue;
        }
        if (a < b) {
            int val = 0;
            if (x <= y) {
                val = x * (b - a);
            } else {
                if ((b - a) % 2 == 0) {
                    val = (x + y) * (b - a) / 2;
                } else if (a % 2 == 0) {
                    int x_count = (b - a) / 2;
                    int y_count = (b - a) - x_count;
                    val = x_count * x + y_count * y;
                } else {
                    int y_count = (b - a) / 2;
                    int x_count = (b - a) - y_count;
                    val = x_count * x + y_count * y;
                }
            }
            cout << val << "\n";
        }
    }
}
