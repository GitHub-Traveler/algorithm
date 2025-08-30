#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<pair<int, int>> twoSum(vector<int> &nums_sorted, int left, int right, int value) {
        vector<pair<int, int>> pairs;
        pair<int, int> current_pair = {INT_MIN, INT_MIN};
        int total;
        while (left < right) {
            total = nums_sorted[left] + nums_sorted[right];
            if (total == value) {
                if (!(current_pair.first == nums_sorted[left] &&
                      current_pair.second == nums_sorted[right])) {
                    current_pair = (pair<int, int>){nums_sorted[left], nums_sorted[right]};
                    pairs.push_back(current_pair);
                }

                left++;
                right--;
            } else if (total < value) {
                left++;
            } else {
                right--;
            }
        }
        return pairs;
    }
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> triplets;
        vector<pair<int, int>> pairs;
        int prev_num = INT_MIN;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] == prev_num) {
                continue;
            }
            pairs = twoSum(nums, i + 1, nums.size() - 1, -nums[i]);
            for (int j = 0; j < pairs.size(); j++) {
                triplets.push_back(vector<int>{nums[i], pairs[j].first, pairs[j].second});
                prev_num = nums[i];
            }
        }
        return triplets;
    }
};

int main(int argc, char *argv[]) {
    Solution i;
    vector<int> sample = {-2, 0, 0, 2, 2};
    vector<vector<int>> result = i.threeSum(sample);
    return 0;
}