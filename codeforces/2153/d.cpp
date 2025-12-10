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
    vector<i64> a(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<i64> b = a;
    i64 temp_result = 0;
    for (int i = 0; i < n; i++) {
      int u = (i + 1) % n;
      int v = (i - 1 + n) % n;
      i64 diff_u = abs(b[i] - b[u]);
      i64 diff_v = abs(b[i] - b[v]);
      if (diff_u <= diff_v) {
        b[i] = b[u];
        temp_result += diff_u;
      } else {
        b[i] = b[v];
        temp_result += diff_v;
      }
    }
    i64 temp_result_2 = 0;
    b = a;
    for (int i = 1; i < n + 1; i++) {
      int u = (i + 1) % n;
      int v = (i - 1 + n) % n;
      i64 diff_u = abs(b[i % n] - b[u]);
      i64 diff_v = abs(b[i % n] - b[v]);
      if (diff_u <= diff_v) {
        b[i % n] = b[u];
        temp_result_2 += diff_u;
      } else {
        b[i % n] = b[v];
        temp_result_2 += diff_v;
      }
    }
    cout << "Results are: " << temp_result << " "
         << temp_result_2 << "\n";
    cout << min(temp_result, temp_result_2)
         << "\n";
  }
}
