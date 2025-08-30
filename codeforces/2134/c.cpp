#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        i64 n = 0;
        cin >> n;
        vector<i64> a(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        i64 result = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 1) {
                if (a[i] < a[i - 1]) {
                    result += a[i - 1] - a[i];
                    a[i - 1] = a[i];
                }
                if (i < n - 1) {
                    if (a[i] < a[i + 1]) {
                        result += a[i + 1] - a[i];
                        a[i + 1] = a[i];
                    }
                }
            }
        }
        for (int i = 0; i < n - 2; i++) {
            if (i % 2 == 0) {
                if (a[i + 1] < (a[i] + a[i + 2])) {
                    i64 temp = a[i] + a[i + 2] - a[i + 1];
                    result += temp;
                    a[i + 2] -= temp;
                }
            }
        }
        cout << result << "\n";
    }
}
