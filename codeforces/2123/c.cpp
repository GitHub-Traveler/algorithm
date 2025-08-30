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
        vector<int> arr(n, 0);
        vector<int> dp_suffix(n, 0);
        vector<int> dp_prefix(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (i == 0) {
                dp_prefix[i] = arr[i];
            } else {
                dp_prefix[i] = min(arr[i], dp_prefix[i - 1]);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == (n - 1)) {
                dp_suffix[i] = arr[i];
            } else {
                dp_suffix[i] = max(arr[i], dp_suffix[i + 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (dp_suffix[i] != arr[i] && dp_prefix[i] != arr[i]) {
                cout << 0;
                continue;
            }
            cout << 1;
        }
        cout << "\n";
    }
}
