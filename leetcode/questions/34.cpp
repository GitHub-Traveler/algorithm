#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return (vector<int> {-1, -1});
        }
        int sup = -1, inf = -1, pivot, left = 0, right = nums.size() - 1;
        while (left < right) {
            pivot = (int) (left + right) / 2;
            if (nums[pivot] == target) {
                right = pivot;
            } else if (nums[pivot] > target) {
                right = pivot - 1;
            } else {
                left = pivot + 1;
            }
        }
        if (nums[left] == target) {
            inf = left;
        } else {
            vector<int> result = {-1, -1}; return result;
        }
        left = 0, right = nums.size() - 1;
        while (left < right) {
            pivot = ceil((left + right)/ (float) 2) ;
            if (nums[pivot] == target) {
                left = pivot;
            } else if (nums[pivot] < target) {
                left = pivot + 1;
            } else {
                right = pivot - 1;
            } 
        }
        sup = right;
        vector<int> result = {inf, sup};
        return result;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> nums = {5,7,7,8,8,10};
    vector<int> result = s.searchRange(nums, 8);
    return 0;
}