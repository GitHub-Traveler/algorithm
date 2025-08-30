#include <iostream>
using namespace std;

int main() {
  int c;
  while (true) {
    cin >> c;
    if (c == 42) {
      break;
    }
    cout << c << endl;
  }
  return 0;
}
