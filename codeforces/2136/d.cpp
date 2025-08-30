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
        const i64 UPRIGHT[2] = {1000000000, 1000000000};
        const i64 UPLEFT[2] = {-1000000000, 1000000000};
        vector<vector<int>> a(n, vector<int>(2, 0));
        for (int i = 0; i < n; i++) {
            cin >> a[i][0] >> a[i][1];
        }
        i64 min_dist_upleft = (i64)1e10;
        i64 min_dist_upright = (i64)1e10;
        vector<vector<i64>> dist(n, vector<i64>(4, 0));
        for (int i = 0; i < n; i++) {
            min_dist_upleft = min(min_dist_upleft, abs(UPLEFT[0] - a[i][0]) + abs(UPLEFT[1] - a[i][1]));
            min_dist_upright = min(min_dist_upright, abs(UPRIGHT[0] - a[i][0]) + abs(UPRIGHT[1] - a[i][1]));
        }
        i64 temp = 0LL;
        cout << "? U " << 1000000000 << endl;
        cin >> temp;
        cout << "? U " << 1000000000 << endl;
        cin >> temp;
        cout << "? R " << 1000000000 << endl;
        cin >> temp;
        cout << "? R " << 1000000000 << endl;
        cin >> temp;
        i64 dist_upright = temp - min_dist_upright;

        cout << "? L " << 1000000000 << endl;
        cin >> temp;
        cout << "? L " << 1000000000 << endl;
        cin >> temp;
        cout << "? L " << 1000000000 << endl;
        cin >> temp;
        cout << "? L " << 1000000000 << endl;
        cin >> temp;
        i64 dist_upleft = temp - min_dist_upleft;
        i64 a_final = (2LL * 1000000000LL - dist_upleft + dist_upright) / 2;
        i64 b_final = dist_upright - a_final;
        i64 x_final = a_final + 1000000000LL - 2LL * 1000000000LL;
        i64 y_final = b_final + 1000000000LL - 2LL * 1000000000LL;
        cout << "! " << x_final << " " << y_final << endl;
        // cin >> temp;
    }
}
