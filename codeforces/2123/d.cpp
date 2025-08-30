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
        int n = 0;
        int k = 0;
        cin >> n >> k;
        vector<bool> arr(n);
        int count_1 = 0;
        for (int i = 0; i < n; i++) {
            char c = ' ';
            cin >> c;
            arr[i] = (c == '1');
            if (arr[i]) {
                count_1++;
            }
        }

        if (count_1 <= k) {
            cout << "ALICE" << "\n";
            continue;
        } else {
            if (n <= k) {
                cout << "ALICE" << "\n";
                continue;
            }
            if (n >= 2 * k) {
                cout << "BOB" << "\n";
                continue;
            }
            cout << "ALICE" << "\n";
            // int overlap = 2 * k - n;
            // int border = n - k;
            // int max_add = k - overlap;
            // if (max_add < ())
        }
    }
}
