#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int x = 0;
        int y = 0;
        int k = 0;
        cin >> x >> y >> k;
        int common = gcd(x, y);
        int n_divide = 0;
        int n_mult = 0;
        int upper_limit = 0;
        x /= common;
        y /= common;
        upper_limit = min(k, (int)sqrt(x));
        bool impossible = false;
        // cout << x << " " << y << endl;
        while (x != 1) {
            n_divide++;
            if (x <= k) {
                break;
            }
            impossible = true;
            for (int i = upper_limit; i > 1; i--) {
                if (x % i == 0) {
                    // cout << "i o day" << i << endl;
                    x /= i;
                    impossible = false;
                    break;
                }
            }
            if (impossible) {
                break;
            }
        }
        // cout << "impossible " << impossible << endl;
        if (impossible) {
            cout << -1 << "\n";
            continue;
        }
        upper_limit = min(k, (int)sqrt(y));
        while (y != 1) {
            n_mult++;
            if (y <= k) {
                break;
            }
            impossible = true;
            // cout << impossible << "co khong" << endl;
            // cout << "y o day" << y << endl;
            // cout << "upper limit " << upper_limit << endl;
            for (int i = upper_limit; i > 1; i--) {
                if (y % i == 0) {
                    if (t == 1) {
                        cout << "division " << i << endl;
                    }
                    y /= i;
                    impossible = false;
                    break;
                }
            }
            // cout << impossible << "co khong" << endl;
            if (impossible) {
                break;
            }
        }
        // cout << n_divide << " " << n_mult << endl;
        if (impossible) {
            cout << -1 << "\n";
            continue;
        }
        cout << n_divide << " " << n_mult << "\n";
        cout << n_divide + n_mult << "\n";
    }
    return 0;
}
