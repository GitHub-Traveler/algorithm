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
        i64 n = 0, c = 0;
        cin >> n >> c;
        vector<i64> arr(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int result = 0;
        vector<i64> new_arr;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= c) {
                new_arr.emplace_back(arr[i]);
            } else {
                result++;
            }
        }
        sort(new_arr.begin(), new_arr.end());
        i64 current_multiplier = 1;
        // cout << "debug" << "\n";
        for (int i = new_arr.size() - 1; i >= 0; i--) {
            // cout << new_arr[i] << "\n";
            if (new_arr[i] * current_multiplier <= c) {
                current_multiplier *= 2;
                new_arr.pop_back();
            } else {
                new_arr.pop_back();
                result++;
            }
        }
        cout << result << "\n";
    }
}
