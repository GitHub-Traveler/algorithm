#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums) {
        vector<int> count;
        int length = nums.size();
        int state = 0;
        int current_count = 0;
        if (nums[0] == 0) {
            count.emplace_back(0);
            state = 0;
        } else {
            state = 1;
        }
        for (int i = 0; i < length; i++) {
            if (nums[i] == state) {
                current_count++;
            } else {
                count.emplace_back(current_count);
                current_count = 1;
                state = 1 - state;
            }
        }
        count.emplace_back(current_count);
        int count_size = count.size();
        int result = 0;
        if (count_size == 1)
            return length - 1;
        for (int i = 0; i < count_size; i += 2) {
            result = max(result, count[i]);
        }
        for (int i = 0; i < count_size - 2; i += 2) {
            if (count[i + 1] == 1)
                result = max(result, count[i] + count[i + 2]);
        }
        return result;
    }
};

int main() {
    Solution test = Solution();
    vector<int> input = {1, 1, 1};
    int sol = test.longestSubarray(input);
    cout << "Solution: " << sol << endl;
    return 0;
}
