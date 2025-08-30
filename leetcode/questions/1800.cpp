#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

class Solution {
  public:
    int maxAscendingSum(std::vector<int> nums) {
        int max_size = nums.size();
        if (max_size == 1) {
            return nums[0];
        }
        int max_sum = nums[0];
        int curr_max_sum = nums[0];
        for (int i = 1; i < max_size; i++) {
            if (nums[i] > nums[i - 1]) {
                curr_max_sum += nums[i];
            } else {
                curr_max_sum = nums[i];
            }
            max_sum = std::max(max_sum, curr_max_sum);
        }
        return max_sum;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    std::vector<int> test_array = {10, 20, 30, 40, 50};
    std::cout << sol.maxAscendingSum(test_array) << std::endl;
    return 0;
}
