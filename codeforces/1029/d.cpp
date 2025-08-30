#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>
using namespace std;
// tuple<int, int, int> extended_gcd(int a, int b) {
//     if (b == 0) {
//         return {a, 1, 0};
//     }
//     auto [gcd, x1, y1] = extended_gcd(b, a % b);
//     int x = y1;
//     int y = x1 - (a / b) * y1;
//
//     return {gcd, x, y};
// }
//
int main() {
    int t;
    int n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> a(n);
        bool broken = false;
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        int y = (2 * a[0] - a[1]) / (n + 1);
        int x = a[1] - a[0] + y;
        for (int j = 0; j < n; j++) {
            int not_zerod = a[j] - x * (j + 1) - y * (n - j);
            if (not_zerod) {
                broken = true;
                break;
            }
        }
        if (!broken) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}
