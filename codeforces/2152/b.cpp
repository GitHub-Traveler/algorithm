#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
  int t = 0;
  cin >> t;
  while (t--) {
    i64 n = 0;
    i64 rk = 0, ck = 0, rd = 0, cd = 0;
    cin >> n >> rk >> ck >> rd >> cd;
    if (rk == rd) {
      if (ck < cd) {
        cout << cd << "\n";
        continue;
      } else if (ck > cd) {
        cout << n - cd << "\n";
        continue;
      }
    } else if (ck == cd) {
      if (rk < rd) {
        cout << rd << "\n";
        continue;
      } else if (rk > rd) {
        cout << n - rd << "\n";
        continue;
      }
    } else {
      if (ck < cd && rk < rd) {
        cout << max(cd, rd) << "\n";
        continue;
      }
      if (ck < cd && rk > rd) {
        cout << max(cd, n - rd) << "\n";
        continue;
      }
      if (ck > cd && rk < rd) {
        cout << max(n - cd, rd) << "\n";
        continue;
      }
      if (ck > cd && rk > rd) {
        cout << max(n - cd, n - rd) << "\n";
        continue;
      }
    }
  }
}
