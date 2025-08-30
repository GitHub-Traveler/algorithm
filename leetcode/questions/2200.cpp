#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k) {
        vector<bool> result(nums.size(), false);
        vector<int> final_result;
        int latest_index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == key) {
                int start = max(i - k, latest_index);
                int end = min((int)nums.size() - 1, i + k);
                for (int i = start; i <= end; i++) {
                    result[i] = true;
                }
                latest_index = end + 1;
                if (latest_index == nums.size()) {
                    break;
                }
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (result[i]) {
                final_result.emplace_back(i);
            }
        }
        return final_result;
    }
};

int main() {
    Solution sl = Solution();
    vector<int> nums = {3, 4, 9, 1, 3, 9, 5};
    int key = 9;
    int k = 1;
    vector<int> result = sl.findKDistantIndices(nums, key, k);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}
