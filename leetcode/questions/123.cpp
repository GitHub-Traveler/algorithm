#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int size = prices.size();
        int dp_left[size];
        int dp_right[size];
        int lowest_left = INT_MAX, highest_right = INT_MIN;
        int highest_gain_left = 0, highest_gain_right = 0, highest_gain = 0;
        int i;
        for (i = 0; i < size; i++) {
            lowest_left = min(lowest_left, prices[i]);
            dp_left[i] = highest_gain_left = max(highest_gain_left, prices[i] - lowest_left);
        }

        for (i = size - 1; i >= 0; i--) {
            highest_right = max(highest_right, prices[i]);
            dp_right[i] = highest_gain_right = max(highest_gain_right, highest_right - prices[i]);
        }

        highest_gain = dp_left[size - 1];
        for (i = 1; i < size - 1; i++) {
            highest_gain = max(highest_gain, dp_left[i] + dp_right[i+1]);
        }
        return highest_gain;
    }
};