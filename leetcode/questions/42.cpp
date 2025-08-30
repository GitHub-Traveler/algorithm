#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left_max = INT_MIN, right_max = INT_MIN;
        int left = 0, right = height.size() - 1;
        int trapped_water = 0;
        while (left <= right) {
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            if (left_max < right_max) {
                trapped_water += (left_max - height[left++]);
            } else {
                trapped_water += (right_max - height[right--]);
            }
        }
        return trapped_water;
    }
};