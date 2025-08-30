#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int> &nums) {
        int max_length = nums.size();
        if (max_length == 1) {
            return 3;
        }
        int current_length = 1;
        int longest_length = 1;
        bool decreasing = true;
        for (int i = 1; i < nums.size(); i++) {
            if (decreasing) {
                if (nums[i] < nums[i - 1]) {
                    current_length++;
                } else {
                    decreasing = false;
                    longest_length = max(longest_length, current_length);
                    if (nums[i] == nums[i - 1]) {
                        current_length = 1;
                    } else {
                        current_length = 2;
                    }
                }
            } else {
                if (nums[i] > nums[i - 1]) {
                    current_length++;
                } else {
                    decreasing = true;
                    longest_length = max(longest_length, current_length);
                    if (nums[i] == nums[i - 1]) {
                        current_length = 1;
                    } else {
                        current_length = 2;
                    }
                }
            }
        }
        longest_length = max(longest_length, current_length);
        return longest_length;
    }
};

int main() {
    Solution test = Solution();
    vector<int> array = {3, 2, 1};
    cout << test.longestMonotonicSubarray(array) << endl;
    return 0;
}
