#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i;
        for (i = 0; i < n; i++)
            while (1 <= nums[i] && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        for (i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;
        return n + 1;
    }
};


int main() {
    Solution sl = Solution();
    vector<int> nums = {3,4,-1,1};
    cout << sl.firstMissingPositive(nums);
}