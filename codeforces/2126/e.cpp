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
        cin >> n;
        vector<int> p(n, 0);
        vector<int> s(n, 0);
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        // for (int i = 0; i < n; i++) {
        //     cout << p[i];
        // }
        // for (int i = 0; i < n; i++) {
        //     cout << s[i];
        // }
        bool result = true;
        for (int i = 0; i < n; i++) {
            if (p[i] % s[i] == 0 || s[i] % p[i] == 0) {
                a[i] = max(p[i], s[i]);
            } else {
                result = false;
                break;
            }
        }
        if (!result) {
            cout << "NO" << "\n";
            continue;
        }
        // for (int i = 0; i < n; i++) {
        //     cout << a[i] << " ";
        // }
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (p[i] != a[i] || s[n - i - 1] != a[n - i - 1]) {
                    result = false;
                    break;
                }
            } else {
                if (p[i] != gcd(p[i - 1], a[i]) || s[n - i - 1] != gcd(s[n - i], a[n - i - 1])) {
                    result = false;
                    break;
                }
            }
        }
        if (result) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}
