#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int l = 0, r = -1;
        int temp;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {l = i - 1; r = i; continue;}
            if (nums[i] > nums[l]) r = i;
        }
        if (r == -1) {
            for (int i = 0; i < floor((nums.size() - 1) / 2); i++) {
                temp = nums[nums.size() - 1 - i];
                nums[nums.size() - 1 - i] = nums[i];
                nums[i] = temp;   
            }
            return; 
        }
        temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;    
        for (int i = l + 1; i <= floor((nums.size() + l) / 2); i++) {
            temp = nums[i];
            nums[i] = nums[nums.size() + l - i];
            nums[nums.size() + l - i] = temp;
        }
    }
};


int main(int argc, char* argv[]) {
    Solution s;
    vector<int> nums = {1,3,2};
    s.nextPermutation(nums);
    return 0;
}