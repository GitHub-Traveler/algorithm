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
    vector<i64> residual;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    i64 counter = n - 1;
    i64 totalEdgeSize = 0;
    i64 edges = 0;
    while (counter >= 0) {
      if (counter > 0 &&
          a[counter] == a[counter - 1]) {
        edges += 1;
        totalEdgeSize += a[counter];
        counter -= 2;
      } else {
        residual.push_back(a[counter]);
        counter--;
      }
    }
    i64 totalBaseSize = -1;
    i64 np = residual.size();
    for (int i = 0; i < np; i++) {
      if (residual[i] < totalEdgeSize * 2)
        totalBaseSize =
            max(totalBaseSize, residual[i]);
    }
    for (int i = 1; i < np; i++) {
      if ((residual[i - 1] - residual[i]) <
          totalEdgeSize * 2)
        totalBaseSize =
            max(totalBaseSize,
                residual[i - 1] + residual[i]);
    }
    if (edges == 0) {
      cout << 0 << "\n";
    } else if (edges == 1) {
      if (totalBaseSize < 0) {
        cout << 0 << "\n";
      } else {
        cout << totalBaseSize + totalEdgeSize * 2
             << "\n";
      }
    } else {
      if (totalBaseSize < 0) {
        cout << totalEdgeSize * 2 << "\n";
      } else {
        cout << totalBaseSize + totalEdgeSize * 2
             << "\n";
      }
    }
  }
}
