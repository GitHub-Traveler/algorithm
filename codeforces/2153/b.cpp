#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
  int t = 0;
  cin >> t;
  while (t--) {
    bool possible = true;
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    for (int i = 0; i < 31; i++) {
      int temp = 0;
      if (((a >> i) & 1))
        temp++;
      if (((b >> i) & 1))
        temp++;
      if (((c >> i) & 1))
        temp++;
      if (temp == 2) {
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
