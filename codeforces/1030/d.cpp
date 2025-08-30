
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    cout << 2 * n - 3 << "\n";
    for (int j = 0; j < n; j++) {
      if (j == 0) {
        cout << j + 1 << " " << 1 << " " << n << "\n";
      } else if (j == 1) {
        cout << j + 1 << " " << 1 << " " << n - 1 << "\n";
      } else if (j == n - 1) {
        cout << j + 1 << " " << 2 << " " << n << "\n";
      } else {
        cout << j + 1 << " " << 1 << " " << n - j << "\n";
        cout << j + 1 << " " << n - j + 1 << " " << n << "\n";
      }
    }
  }
  return 0;
}
