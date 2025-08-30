#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int n = 0, k = 0;
        cin >> n >> k;
        vector<bool> a(n, 0);
        int total = 0;
        int current = -1;
        for (int i = 0; i < n; i++) {
            int temp = 0;
            cin >> temp;
            a[i] = (bool)temp;
        }
        for (int i = 0; i <= n; i++) {
            bool temp = false;
            if (i == n) {
                temp = 1;
            } else {
                temp = a[i];
            }
            if (temp) {
                int length = i - current - 1;
                // cout << "debug " << length << "\n";
                current = i;
                if (length >= k) {
                    total += (1 + (length - k) / (k + 1));
                }
            }
        }

        cout << total << "\n";
    }
}
