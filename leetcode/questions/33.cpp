#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, pivot;
        int sup_right = nums[nums.size() - 1], inf_left = nums[0];
        bool left_side = (target >= inf_left);
        if (target > sup_right && target < inf_left) {
            return -1;
        }
        while (left <= right) {
            pivot = (int) (left + right) / 2;
            if (nums[pivot] == target) {
                return pivot;
            }
            if (nums[pivot] >= inf_left) {
                if (nums[pivot] < target || !left_side) {
                    left = pivot + 1;
                } else {
                    right = pivot - 1;
                }
            } else {
                if (nums[pivot] > target || left_side) {
                    right = pivot - 1;
                } else {
                    left = pivot + 1;
                }
            }
        }
        return -1;
    }
};


int main(int argc, char* argv[]) {
    Solution s;
    vector<int> nums = {4,5,6,7,0,1,2};
    int result = s.search(nums, 0);
    return 0;
}