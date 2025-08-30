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
        vector<vector<int>> points(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++) {
            int x = 0, y = 0;
            cin >> x >> y;
            points[i][0] = x;
            points[i][1] = y;
            points[i][2] = i + 1;
        }
        sort(points.begin(), points.end());
        int total_sum = 0;
        for (int i = 0; i < n / 2; i++) {
            cout << points[i][2] << " " << points[n - 1 - i][2] << "\n";
            total_sum += abs(points[i][0] - points[n - 1 - i][0]);
            total_sum += abs(points[i][1] - points[n - 1 - i][1]);
        }
        cout << "Total sum is: " << total_sum << "\n";
    }
}
