#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] - a[0] > b[1] - b[0];
        });
        int total = 0;
        int energy = 0;
        for (vector<int> &task : tasks) {
            if (energy < task[1]) {
                total += task[1] - energy;
                energy = task[1];
            }
            energy -= task[0];
        }
        return total;
    }
};

int main() {
    Solution test = Solution();
    vector<vector<int>>array = {{1, 2}, {2, 4}, {4, 8}};
    cout << test.minimumEffort(array) << endl;
    return 0;
}