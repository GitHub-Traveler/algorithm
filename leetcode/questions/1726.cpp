#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int max_size = nums.size();
        int total_number = max_size * (max_size - 1) / 2;
        vector<int> products(total_number);
        for (int i = 0; i < max_size; i++) {
            for (int j = i + 1; j < max_size; j++) {
                
            }
        }
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    vector<int> nums = {2, 3, 4, 6};
    cout << sol.tupleSameProduct(nums) << endl;
    return 0;
}

