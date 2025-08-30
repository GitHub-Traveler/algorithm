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
        int j = 0;
        int k = 0;
        cin >> n >> j >> k;
        vector<int> arr(n);
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            minimum = min(arr[i], minimum);
            maximum = max(arr[i], maximum);
        }
        int num = arr[j - 1];
        if (k == 1) {
            if (num != maximum) {
                cout << "NO" << "\n";
                continue;
            }
        }
        cout << "YES" << "\n";
    }
}
