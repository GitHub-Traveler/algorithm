#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> data;
    vector<int> prefix_sum;
    uniform_int_distribution<int> generator;
    uniform_int_distribution<int> horizontal_generator;
    uniform_int_distribution<int> vertical_generator;
    random_device rd;
    mt19937 rng;

public:
    Solution(vector<vector<int>>& rects) {
        prefix_sum.resize(rects.size());
        rng = mt19937(rd());
        data = rects;
        unsigned int total = 0;
        for (unsigned int i = 0; i < rects.size(); i++) {
            prefix_sum[i] = total;
            total +=
                (data[i][2] - data[i][0] + 1) * (data[i][3] - data[i][1] + 1);
        }
        generator = uniform_int_distribution<int>(0, total - 1);
    }

    vector<int> pick() {
        int sample = generator(rng);
        auto it = upper_bound(prefix_sum.begin(), prefix_sum.end(), sample);
        int index = std::distance(prefix_sum.begin(), it) - 1;
        cout << index;
        vector<int> current_rectangle = data[index];
        horizontal_generator = uniform_int_distribution<int>(
            current_rectangle[0], current_rectangle[2]);
        vertical_generator = uniform_int_distribution<int>(
            current_rectangle[1], current_rectangle[3]);
        int horizontal = horizontal_generator(rng);
        int vertical = vertical_generator(rng);
        vector<int> result = {horizontal, vertical};
        return result;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> test_input = {{-2, -2, 1, 1}, {2, 2, 4, 6}};
    Solution sol(test_input);
    sol.pick();
    sol.pick();
    sol.pick();
    sol.pick();
    sol.pick();
    return 0;
}