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
        vector<int> p(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        vector<int> first_pair(2, -1);
        vector<int> last_pair(2, -1);
        int num_zero = 0;
        int missing_number = -1;
        for (int i = 0; i < n; i++) {
            if (p[i] == 0) {
                num_zero++;
                if (missing_number == -1) {
                    missing_number = i + 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (p[i] == missing_number) {
                missing_number = -2;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (p[i] != i + 1) {
                if (first_pair[0] == -1) {
                    first_pair[0] = i + 1;
                } else if (first_pair[1] == -1) {
                    first_pair[1] = i + 1;
                } else {
                    break;
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (p[i] != i + 1) {
                if (last_pair[1] == -1) {
                    last_pair[1] = i + 1;
                } else if (last_pair[0] == -1) {
                    last_pair[0] = i + 1;
                } else {
                    break;
                }
            }
        }

        if (num_zero == 1 && missing_number > 0) {
            if (p[first_pair[0] - 1] == 0) {
                first_pair[0] = first_pair[1];
            }
            if (p[last_pair[1] - 1] == 0) {
                last_pair[1] = last_pair[0];
            }
        }
        // cout << first_pair[0] << " "
        //     << last_pair[1] << "\n";
        if (first_pair[0] == last_pair[1] ||
            first_pair[0] == -1 ||
            last_pair[1] == -1) {
            cout << 0 << "\n";
            continue;
        } else {
            cout << last_pair[1] - first_pair[0] +
                        1
                 << "\n";
        }
    }
}
