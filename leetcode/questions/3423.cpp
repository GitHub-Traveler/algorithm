#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int> &nums) {
        int max_diff = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i != nums.size() - 1) {
                max_diff = max(max_diff, abs(nums[i] - nums[i + 1]));
            } else {
                max_diff = max(max_diff, abs(nums[i] - nums[0]));
            }
        }
        return max_diff;
    }
};
int main(int argc, char *argv[]) {
    Solution sol;
    vector<int> machines = {-5, -10, -5};
    cout << sol.maxAdjacentDistance(machines) << endl;
    return 0;
}
