#include <bits/stdc++.h>
#include <vector>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n = 0;
        cin >> n;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        if (n == 1) {
            cout << 0 << "\n";
            continue;
        }
        if (n == 2) {
            if (abs(arr[0] - arr[1]) % 2 == 0) {
                cout << 0 << "\n";
            } else {
                cout << 1 << "\n";
            }
            continue;
        }
        int left = -1;
        int right = -1;
        for (int i = 0; i < n; i++) {
            if (arr[n - 1] - arr[i] % 2 == 0 && left == -1) {
                left = i;
            }
            if (arr[n - i - 1] - arr[0] % 2 == 0 && left == -1) {
                right = i;
            }
        }
        cout << min(left, right) << "\n";
    }
}
