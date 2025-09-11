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
        i64 n = 0, k = 0;
        cin >> n >> k;
        vector<int> a(n, 0);
        vector<int> counter(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            counter[a[i]]++;
        }
        int mex = 0;
        for (int i = 0; i < n; i++) {
            if (counter[a[i]] == 0) {
                mex = i;
                break;
            }
        }
        i64 result = mex * n;
        int lowest_mult = -1;
        for (int i = 0; i < mex; i++) {
            if (counter[i] < 2) {
                result += i;
                result -= mex;
            } else {
                if (lowest_mult == -1) {
                    lowest_mult = i;
                }
            }
        }
        if (k == 1) {
            cout << result << "\n";
            continue;
        } else if (k == 2) {
            result = lowest_mult * (n - lowest_mult);
            for (int i = 0; i < lowest_mult; i++) {
                result += i;
            }
        } else {
            if (k % 2 == 0) {
                result = lowest_mult * (n - lowest_mult);
                for (int i = 0; i < lowest_mult; i++) {
                    result += i;
                }
            } else {
                result = (lowest_mult + 1) * (n - lowest_mult);
                for (int i = 0; i < lowest_mult; i++) {
                    result += i;
                }
            }
        }
        cout << result << "\n";
    }
}
