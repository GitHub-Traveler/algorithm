#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        string str = " ";
        int n = 0;
        cin >> n;
        cin >> str;
        int num0 = 0;
        int wrong_pos = 0;
        for (int i = 0; i < n; i++) {
            if (str[i] == '0') {
                num0++;
            }
        }
        for (int i = 0; i < num0; i++) {
            if (str[i] == '1') {
                wrong_pos++;
            }
        }
        cout << wrong_pos << "\n";
    }
}
