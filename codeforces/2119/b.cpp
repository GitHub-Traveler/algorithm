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
        i64 px = 0, py = 0, qx = 0, qy = 0;
        cin >> px >> py >> qx >> qy;
        vector<i64> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        i64 squared_dist = (px - qx) * (px - qx) + (py - qy) * (py - qy);
        // cout << "debug";
        // cout << squared_dist << "\n";
        if (n == 1) {
            if (arr[0] * arr[0] == squared_dist) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
            continue;
        }
        if (n == 2) {
            i64 first_dist = arr[0];
            pair<i64, i64> range(0, 0);
            range.first = abs(arr[0] - arr[1]);
            range.second = abs(arr[0] + arr[1]);
            if (squared_dist >= (range.first * range.first) && squared_dist <= (range.second * range.second)) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
            continue;
        }
        if (n > 2) {
            i64 first_dist = arr[0];
            pair<i64, i64> temp(0, 0);
            pair<i64, i64> range(0, 0);
            range.first = abs(arr[0] - arr[1]);
            range.second = abs(arr[0] + arr[1]);
            for (int i = 2; i < n; i++) {
                temp.first = min(abs(range.first - arr[i]), abs(range.second - arr[i]));
                if (range.first < arr[i] && arr[i] < range.second) {
                    temp.first = 0;
                }
                temp.second = max(abs(range.first + arr[i]), abs(range.second + arr[i]));
                range = temp;
            }
            if (squared_dist >= (range.first * range.first) && squared_dist <= (range.second * range.second)) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
    }
}
