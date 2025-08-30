#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int a, x, y;
        cin >> a >> x >> y;
        bool con1 = a < x && x < y;
        bool con2 = a > x && x > y;
        bool con3 = a > y && y > x;
        bool con4 = a < y && y < x;
        bool result = con1 || con2 || con3 || con4;
        if (result) {
            cout << "yes" << "\n";
        } else {
            cout << "no" << "\n";
        }
    }
}
