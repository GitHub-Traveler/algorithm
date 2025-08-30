#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int counter = 1, current_num = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == current_num) continue;
            nums[counter] = nums[i];
            counter++;
            current_num = nums[i];
        }
        return counter;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> nums = {1, 1, 2, 2, 3};
    s.removeDuplicates(nums);
    return 0;
}