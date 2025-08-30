#include <vector>

using namespace std;

class Solution {
public:
    int countHillValley(vector<int> &nums) {
        int result = 0;
        int currentState = 0;
        int nothing = true;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nothing = false;
                break;
            }
        }
        if (nothing) {
            return 0;
        } else {
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] > nums[i - 1]) {
                    if (currentState == 0) {
                        currentState = 1;
                    }
                    if (currentState == -1) {
                        currentState = 1;
                        result++;
                    }
                } else if (nums[i] < nums[i - 1]) {
                    if (currentState == 0) {
                        currentState = -1;
                    }
                    if (currentState == 1) {
                        currentState = -1;
                        result++;
                    }
                }
            }
            return result;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {1, 1, 2, 2, 3};
    s.countHillValley(nums);
    return 0;
}
