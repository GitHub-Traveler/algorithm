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
        i64 a = 0, b = 0;
        cin >> a >> b;
        if (b % 2 == 1) {
            if (a % 2 == 1) {
                cout << (a * b + 1) << "\n";
            } else {
                cout << -1 << "\n";
            }
        } else {
            if (a % 2 == 1) {
                if (b % 4 == 0) {
                    cout << (a * b / 2 + 2) << "\n";
                } else {
                    cout << -1 << "\n";
                }
            } else {
                cout << (a * b / 2 + 2) << "\n";
            }
        }
    }
}
