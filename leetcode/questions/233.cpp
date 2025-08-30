#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countDigitOne(int n) {
    string s = to_string(n);
    int num_digits = s.length();
    int total_count = 0;
    if (num_digits == 1) {
      if (n >= 1)
        return 1;
      else
        return 0;
    }
    int first_number = s[0] - '0';

    if (first_number == 1) {
      total_count = (num_digits - 1) * pow(10, num_digits - 2) +
                    (n + 1 - pow(10, num_digits - 1)) +
                    countDigitOne(n - pow(10, num_digits - 1));
    } else {
      total_count = first_number * (num_digits - 1) * pow(10, num_digits - 2) +
                    pow(10, num_digits - 1) +
                    countDigitOne(n - pow(10, num_digits - 1) * first_number);
    }
    return total_count;
  }
};

int main() {
  Solution test = Solution();
  int n = test.countDigitOne(20);
  return 0;
}
