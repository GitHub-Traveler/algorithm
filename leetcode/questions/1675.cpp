#include <bits/stdc++.h>
#include <iostream>
#include <vector>

class Solution {
public:
  int minimumDeviation(std::vector<int> &nums) {
    int len = nums.size();
    int minimized[len];
    int maximum = 0;
    int min_dev = INT_MAX;
    for (int i = 0; i < len; i++) {
      minimized[i] = nums[i];
      while (minimized[i] | 0) {
        minimized[i] >>= 1;
      }
      maximum = std::max(minimized[i], maximum);
    }
    for (int i = 0; i < len; i++) {
      if (minimized[i] != maximum) {
        int current_dis = INT_MAX;
        while (minimized[i] <= nums[i]) {
          if (current_dis > std::abs(minimized[i] - maximum)) {
            current_dis = std::abs(minimized[i] - maximum);
          } else {
            if (minimized[i] > maximum) {
              maximum = minimized[i];
            }
            if (minimized[i] < minimum) {
              minimum = minimized[i];
            }
            break;
          }
          minimized[i] = minimized[i] * 2;
        }
        min_dev = std::min(maximum - minimum, min_dev);
      }
    }
    return min_dev;
  }
};
int main() {
  Solution sl = Solution();
  std::vector<int> nums = {1, 2, 3, 4};
  std::cout << sl.minimumDeviation(nums);
  return 0;
}
