#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int w, h, a, b;
    cin >> w >> h >> a >> b;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (((x2 - x1) >= a && (x2 - x1) % a == 0) ||
        ((x1 - x2) >= a && (x1 - x2) % a == 0) ||
        ((y2 - y1) >= b && (y2 - y1) % b == 0) ||
        ((y1 - y2) >= b && (y1 - y2) % b == 0))
      cout << "YES" << endl;
    else {
      cout << "NO" << endl;
    }
  }
}
