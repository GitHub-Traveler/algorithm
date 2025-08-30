#include <bits/stdc++.h>
#include <stack>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s = "";
        cin >> s;
        stack<int> stk;
        int depth = 0;
        int first_right_brk = -1;
        int left_brk = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                depth++;
                if (first_right_brk != -1) {
                    left_brk = i;
                    break;
                }
            } else {
                depth--;
                if (depth == 0 && first_right_brk == -1) {
                    first_right_brk = i;
                }
            }
        }
        if (left_brk == -1 || first_right_brk == -1) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }
}
