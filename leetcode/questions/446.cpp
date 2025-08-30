#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long, int> hashtable[n];
        hashtable[1].insert({nums[1] - nums[0], 1});
        int i, j, num_slices;
        for (i = 2; i < n; i++)
            for (j = 0; j < i; j++) {
                long gap = (long) nums[i] - nums[j];
                if (hashtable[j].find(gap) != hashtable[j].end()) {
                    num_slices += hashtable[j][gap];
                    hashtable[i][gap] += hashtable[j][gap];
                }
                hashtable[i][gap] += 1;
            }
        return num_slices;
    }
};
