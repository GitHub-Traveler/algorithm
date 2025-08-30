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
        int result = min(2 * arr[0], arr[0] + arr[1]);
        cout << result << "\n";
    }
}
