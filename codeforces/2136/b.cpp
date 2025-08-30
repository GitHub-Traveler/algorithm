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
        string binString;
        cin >> binString;
        int length_1 = 0;
        bool possible = true;
        for (int i = 0; i < n; i++) {
            if (binString[i] == '1') {
                length_1 += 1;
            } else {
                length_1 = 0;
            }
            if (length_1 >= k) {
                possible = false;
                break;
            }
        }
        int counter = 1;
        if (possible) {
            cout << "YES" << "\n";
            vector<int> result(n, 0);
            for (int i = 0; i < n; i++) {
                if (binString[i] == '1') {
                    result[i] = counter;
                    counter++;
                }
            }
            for (int i = 0; i < n; i++) {
                if (binString[i] == '0') {
                    result[i] = counter;
                    counter++;
                }
            }
            cout << result[0];
            for (int i = 1; i < n; i++) {
                cout << " " << result[i];
            }
            cout << "\n";

        } else {
            cout << "NO" << "\n";
        }
    }
}
