#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
  int maxArea(vector<int>& heights) {
    int left = 0, right = heights.size() - 1;
    int leftHeight = heights[left], rightHeight = heights[right];
    int maximum = min(leftHeight, rightHeight) * (right - left);
    while (left < right) {
      if (leftHeight > rightHeight) {
        right--;
        if (heights[right] > rightHeight) {
          rightHeight = heights[right];
          maximum = max(maximum, min(leftHeight, rightHeight) * (right - left));
        }
      } else {
        left++;
        if (heights[left] > leftHeight) {
          leftHeight = heights[left];
          maximum = max(maximum, min(leftHeight, rightHeight) * (right - left));
        }
      }  
    }

    return maximum;
  }
};