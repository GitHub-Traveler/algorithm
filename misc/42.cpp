#include <iostream>
using namespace std;

int reverseNumber(int n) {
  int reversed = 0;
  while (n != 0) {
    int digit = n % 10;
    reversed = reversed * 10 + digit;
    n /= 10;
  }
  return reversed;
}

int main() {
  int n, a, b, s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    s = reverseNumber(reverseNumber(a) + reverseNumber(b));
    cout << s << endl;
  }
}
