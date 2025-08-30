#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int size_nums = nums.size();
        vector<vector<int>> dp(size_nums, vector<int>(size_nums, -1));
        
        return helper(nums, 1, nums.size() - 2, dp);
    }
    int helper(vector<int>& nums, int start, int finish, vector<vector<int>>& dp) {
        if (dp[start][finish] != -1)
            return dp[start][finish];
        if (start > finish)
            return 0;
        else if (start == finish)
            return dp[start][finish] = nums[start] * nums[start - 1] * nums[start + 1];
        else {
            int max_coins = 0;
            for (int i = start; i <= finish; i++) {
                if (i == start)
                    max_coins = max(max_coins, helper(nums, i+1, finish, dp) + nums[start] * nums[start - 1] * nums[finish + 1]);
                if (i == finish)
                    max_coins = max(max_coins, helper(nums, start, finish - 1, dp) + nums[finish] * nums[start - 1] * nums[finish + 1]);
                max_coins = max(max_coins, helper(nums, start, i - 1, dp) + helper(nums, i + 1, finish, dp) + nums[start - 1] * nums[finish + 1] * nums[i]);
            }
            return dp[start][finish] = max_coins;
        }
    }
};