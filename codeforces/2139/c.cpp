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
        i64 k = 0, x = 0;
        cin >> k >> x;
        i64 y = (1LL << (k + 1)) - x;
        vector<int> operation;
        while (true) {
            while ((x % 2 == 0) && (y % 2 == 0)) {
                x /= 2LL;
                y /= 2LL;
            }
            if (x > y) {
                x -= y;
                y *= 2;
                operation.emplace_back(2);
            } else if (x < y) {
                y -= x;
                x *= 2;
                operation.emplace_back(1);
            } else {
                break;
            }
        }
        cout << (int)operation.size() << "\n";
        if (operation.empty()) {
            cout << "\n";
            continue;
        }
        cout << operation[operation.size() - 1];
        for (int i = (int)operation.size() - 2; i >= 0; i--) {
            cout << " " << operation[i];
        }
        cout << "\n";
    }
}
