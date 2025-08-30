#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSum(vector<int> &nums) {
        unordered_set<int> cache(0, );
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0 || cache.find(nums[i]) != cache.end()) {
                continue;
            }
            cache.emplace(nums[i]);
            result += nums[i];
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    int result = s.maxSum(nums);
    return 0;
}
