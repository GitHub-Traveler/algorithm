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
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    sort(b.begin(), b.end());
    int result = 1;
    for (int i = 1; i < n; i++) {
      if (b[i - 1] != b[i]) {
        result++;
      }
    }
    cout << result << endl;
    ;
  }
}
