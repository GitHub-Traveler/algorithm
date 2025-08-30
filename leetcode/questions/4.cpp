#include <bits/stdc++.h>

class Solution {
public:
  double findMedianSortedArrays(std::vector<int> &nums1,
                                std::vector<int> &nums2) {
    int x = nums1.size(), y = nums2.size();
    if (x > y) {
      nums1.swap(nums2);
    }

    int low = 0, high = x;
    int partition_nums1, partition_nums2;
    int low_x, low_y, high_x, high_y;
    while (low <= high) {
      partition_nums1 = int((high - low) / 2);
      partition_nums2 = int((x + y + 1) / 2) - partition_nums1;
      if (partition_nums1 == x) {
        low_x = 1e6;
      } else {
        low_x = nums1.at(partition_nums1);
      }

      if (partition_nums1 == 0) {
        high_x = -1e6;
      } else {
        high_x = nums1.at(partition_nums1 - 1);
      }

      if (partition_nums2 == y) {
        low_y = 1e6;
      } else {
        low_y = nums2.at(partition_nums2);
      }

      if (partition_nums2 == 0) {
        high_y = -1e6;
      } else {
        high_y = nums2.at(partition_nums2 - 1);
      }

      if (high_x <= low_y && high_y <= low_x) {
        if (div(x + y, 2).rem == 0) {
          return int((std::max(high_x, high_y) + std::min(low_x, low_y)) / 2);
        } else {
          return std::max(high_x, high_y);
        }
      } else if (high_x > low_y) {
        high = partition_nums1 - 1;
      } else {
        low = partition_nums1 + 1;
      }
    }
    return 0;
  }
};
