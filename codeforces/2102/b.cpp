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
        vector<int> a(n, 0);
        int median = ceil(n / 2);
        int counter = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] = abs(a[i]);
        }
        int possible = true;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[0]) {
                counter++;
            }
            if (counter > (median)) {
                possible = false;
                break;
            }
        }
        if (possible)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}
