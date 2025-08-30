#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int total = 0, n = nums.size();
        int i, highest = 0;
        for (i = 0; i < n; i++) {
            total += nums[i];
        }
        int left = 0, right = total;
loop:
        while (left <= right) {
            int mid = div((left + right), 2).quot;
            int current = 0, num_division = 1;
            for (i = 0; i < n; i++) {
                if (nums[i] > mid) {
                    left = mid + 1;
                    goto loop;
                }
                current += nums[i];
                if (current > mid) {
                    num_division += 1;
                    current = nums[i];
                }
                if (num_division > k) {
                    left = mid + 1;
                    goto loop;
                }
            }
            highest = mid;
            right = mid - 1;
        }
        return highest;
    }
};  


int main() {
    Solution sl = Solution();
    vector<int> nums = {7,2,5,10,8};
    cout << sl.splitArray(nums, 2);
}