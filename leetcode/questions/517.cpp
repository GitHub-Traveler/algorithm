#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int findMinMoves(vector<int> &machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        int length = machines.size();
        if (!(sum % length)) {
            return -1;
        }

        return 0;
    }
};
int main(int argc, char *argv[]) {
    Solution sol;
    vector<int> machines = {1, 0, 5};
    cout << sol.findMinMoves(machines) << endl;
    return 0;
}
