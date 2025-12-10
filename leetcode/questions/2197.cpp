#include <bits/stdc++.h>
#include <vector>
using namespace std;
using i64 = long long;
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int> &nums) {
        int n = nums.size();
        vector<int> result;
        for (int i = 0; i < n; i++) {
            result.push_back(nums[i]);
            while (result.size() >= 2) {
                int currentIndex = result.size() - 1;
                int currentGcd = gcd(result[currentIndex], result[currentIndex - 1]);
                if (currentGcd > 1) {
                    result[currentIndex - 1] = result[currentIndex] * result[currentIndex - 1] / currentGcd;
                    result.pop_back();
                } else {
                    break;
                }
            }
        }
        return result;
    }
};