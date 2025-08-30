#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    bool priority = x > y;
    bool priority2 = a > b;
    int total = 0;
    if (priority) {
      if (priority2) {
        total = (k >= b) ? (k - b) / y + 1 : 0;
      } else {
        total += (k >= b) ? (k - b) / y + 1 : 0;
        if (total == 0) {
          total += (k >= a) ? (k - a) / x + 1 : 0;
        } else {
          int rem = k - y * total;
          // cout << "diagnostic" << k << b << total << endl;
          total += (rem >= a) ? (rem - a) / x + 1 : 0;
        }
      }
    } else {
      if (priority2) {
        total += (k >= a) ? (k - a) / x + 1 : 0;
        if (total == 0) {
          total += (k >= b) ? (k - b) / y + 1 : 0;
        } else {
          int rem = k - x * total;
          // cout << "diagnostic" << k << a << total << endl;
          total += (rem >= b) ? (rem - b) / y + 1 : 0;
        }
      } else {
        total += (k >= a) ? (k - a) / x + 1 : 0;
      }
    }
    cout << total << endl;
  }
  return 0;
}
