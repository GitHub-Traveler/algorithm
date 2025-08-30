#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> maxBurn(vector<vector<int>>& nums, pair<int, int>& startState) {
        int height = nums.size();
        int width = nums[0].size();
        sort(nums.begin(), nums.end());
        vector<vector<bool>> visited(height, vector<bool> (width));
        return nums;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<vector<int>> nums;
    pair<int, int> startState;
    s.maxBurn(nums, startState);
    return 0;
}