#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<int> &nums, int place, int currXor, int &total) {
        if (place == nums.size()) {
            total += currXor;
            return;
        }
        dfs(nums, place + 1, currXor ^ nums[place], total);
        dfs(nums, place + 1, currXor, total);
    }
    int subsetXORSum(vector<int> &nums) {
        int total = 0;
        dfs(nums, 0, 0, total);
        return total;
    }
};
int main(int argc, char *argv[]) {
    Solution sol;
    vector<int> nums = {5, 1, 6};
    cout << sol.subsetXORSum(nums) << endl;
    return 0;
}
