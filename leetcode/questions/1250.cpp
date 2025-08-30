#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  // bool gcd(int a, int b) {
  //   int rem;
  //   int val;
  //   while (a != 1 && b != 1) {
  //     if (a > b) {
  //       rem = a % b;
  //       val = b;
  //       a = rem;
  //     } else {
  //       rem = b % a;
  //       val = a;
  //       b = rem;
  //     }
  //     if (!rem) {
  //       return val;
  //     }
  //   }
  //   return 1;
  // }

  int gcdVector(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    }
    int gcd_current = gcd(nums[0], nums[1]);
    if (nums.size() > 2) {
      for (int i = 2; i < nums.size(); i++) {
        gcd_current = gcd(nums[i], gcd_current);
      }
    }
    return gcd_current;
  }
  bool isGoodArray(vector<int> &nums) {
    return (gcdVector(nums) == 1) ? true : false;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  vector<int> test_vector = {3, 6};
  cout << sol.isGoodArray(test_vector) << endl;
  return 0;
}
