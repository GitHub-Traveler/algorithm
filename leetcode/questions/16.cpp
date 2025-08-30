#include <climits>
#include <vector>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int left, right, diff = INT_MAX, result = INT_MAX, current_sum = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            left = i + 1;
            right =  nums.size() - 1;
            while (left < right) {
                current_sum = nums[i] + nums[left] + nums[right];
                diff = min(diff, abs(current_sum - target));
                if (diff == abs(current_sum - target)) {
                    result = current_sum;
                }
                if (diff == 0) {
                    return result;
                } else if (current_sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    Solution i;
    vector<int> test = {-1,2,1,-4};
    int final = i.threeSumClosest(test, 1);
    return 0;
}