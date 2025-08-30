#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                nums[i] = INT_MIN;
            }
        }
        int counter = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == INT_MIN) continue;
            nums[counter] = nums[i];
            counter++;
        }
        return nums.size() - counter;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> nums = {3, 2, 2, 3};
    s.removeElement(nums, 3);
    return 0;
}