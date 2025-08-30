#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  static bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
  }
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<pair<int, int>> num_pairs;
    for (int i = 0; i < nums.size(); i++) {
      num_pairs.push_back(pair<int, int>{i, nums[i]});
    }
    sort(num_pairs.begin(), num_pairs.end(), cmp);
    int left = 0;
    int right = num_pairs.size() - 1;
    int current = 0;
    while (left <= right) {
      current = num_pairs[left].second + num_pairs[right].second;
      if (current == target) {
        if (num_pairs[left].first > num_pairs[right].first) {
          return (vector<int>){num_pairs[right].first, num_pairs[left].first};
        } else {
          return (vector<int>){num_pairs[left].first, num_pairs[right].first};
        }
      } else if (current > target) {
        right--;
      } else {
        left++;
      }
    }
    return (vector<int>){0, 0};
  }
};
