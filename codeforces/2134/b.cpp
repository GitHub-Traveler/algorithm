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
        i64 n = 0, k = 0;
        cin >> n >> k;
        vector<i64> a(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            i64 residual = a[i] % (k + 1);
            a[i] += (i64)residual * k;
        }
        cout << a[0];
        for (int i = 1; i < n; i++) {
            cout << " " << a[i];
        }
        cout << "\n";
    }
}
