#include <algorithm>
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        if (n == 1) {
            cout << 1 << " " << 1 << "\n";
            continue;
        }
        sort(arr.begin(), arr.end());
        int mex_total = arr[n - 1] + 1;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (arr[i] > 0) {
                    mex_total = 0;
                    break;
                }
            }
            if (i != 0) {
                if (arr[i] - arr[i - 1] > 1) {
                    mex_total = arr[i - 1] + 1;
                    break;
                }
            }
        }
        if (mex_total == 0) {
            for (int i = 0; i < n; i++) {
                cout << 1 << " ";
            }
        } else {
            vector<int> count(mex_total, 0);
            for (int i = 0; i < n; i++) {
                if (arr[i] < mex_total) {
                    count[arr[i]]++;
                }
            }
            sort(count.begin(), count.end());
            // cout << "debug" << "\n";
            // cout << mex_total << "\n";
            // for (int i = 0; i < mex_total; i++) {
            //     cout << count[i] << " ";
            // }
            // cout << "\n";
            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    cout << 1 << " ";
                    continue;
                }
                if ((n - i) < mex_total) {
                    cout << n - i + 1 << " ";
                    continue;
                }
                auto it = upper_bound(count.begin(), count.end(), i);
                int result = distance(count.begin(), it) + 1;
                cout << result << " ";
            }
        }
        cout << 1 << "\n";
    }
}
