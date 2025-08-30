#include <iostream>
#include <vector>
#include <bits/stdc++.h>

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int big = std::max(c, std::max(a, b));
        int sum = a + b + c;
        int remaining = sum - big * 2;
        if (remaining <= 0) {
            return big;
        } else if (remaining % 2 == 0) {
            return (int) (sum / 2);
        } else {
            return (int) ((sum - 1) / 2);
        }
    }
};

int main() {
    Solution sl = Solution();
    std::vector<int> scores = {4,5,6,5};
    std::vector<int> ages = {2,1,2,1};
    std::cout << sl.maximumScore(1, 2, 3);
    return 0;
}