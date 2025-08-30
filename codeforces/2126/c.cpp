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
        int n = 0, k = 0;
        cin >> n >> k;
        vector<int> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        int current_level = h[k - 1];
        int current_waterlevel = 1;
        bool result = true;
        sort(h.begin(), h.end(), less<int>());
        // int current_place = find(h.begin(), h.end(), current_level);
        for (int i = 0; i < n - 1; i++) {
            if (h[i] < current_level) {
                continue;
            }
            if (h[i] + 1 - current_waterlevel >= h[i + 1] - h[i]) {
                current_waterlevel += h[i + 1] - h[i];
            } else {
                result = false;
                break;
            }
        }
        if (result) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}
