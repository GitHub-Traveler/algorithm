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
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n == 1) {
            cout << a[0] << "\n";
        }
        int max_increase = 0;
        int final_element = 0;
        if (n % 2 == 0) {
            final_element = n - 1;
        } else {
            final_element = n - 2;
        }
        vector<int> prefix_max_element(n, 0);
        vector<int> suffix_max_element(n, 0);
        prefix_max_element[1] = a[1];
        suffix_max_element[final_element] = a[final_element];
        for (int i = 3; i < final_element; i += 2) {
            prefix_max_element[i] = max(prefix_max_element[i - 2] + 2, a[i]);
        }
        for (int i = final_element - 2; i >= 1; i -= 2) {
            suffix_max_element[i] = max(suffix_max_element[i + 2] + 2, a[i]);
        }
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (i == 0) {
                    suffix_max_element[i] = suffix_max_element[1] + 1;
                } else if (i == n - 1) {
                    prefix_max_element[i] = prefix_max_element[i - 1] + 1;
                } else {
                    suffix_max_element[i] = suffix_max_element[i + 1] + 1;
                    prefix_max_element[i] = prefix_max_element[i - 1] + 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                max_increase =
                    max(max(max_increase, 2 * (prefix_max_element[i] - a[i])), 2 * (suffix_max_element[i] - a[i]));
            }
        }
        if (n % 2 == 0) {
            max_increase = max(max_increase, n - 2);
        } else {
            max_increase = max(max_increase, n - 1);
        }
        cout << "Max increase is: " << max_increase << "\n";
        i64 final_result = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                final_result += a[i];
            } else {
                final_result -= a[i];
            }
        }
        final_result += max_increase;
        cout << final_result << "\n";
    }
}
