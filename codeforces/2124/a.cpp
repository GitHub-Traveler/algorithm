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
        vector<i64> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int current = arr[0];
        bool possible = false;
        int index = -1;
        for (int i = 1; i < n; i++) {
            if (current <= arr[i]) {
                current = arr[i];
            } else {
                possible = true;
                index = i;
                break;
            }
        }
        if (possible) {
            cout << "YES" << "\n";
            cout << 2 << "\n";
            cout << arr[index - 1] << " " << arr[index] << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}
