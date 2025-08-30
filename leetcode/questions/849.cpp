#include <iostream>
#include <vector>

class Solution {
public:
    public:
    int maxDistToClosest(std::vector<int>& seats) {
        int curr = -1;
        int max = 0;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                if (curr == -1) {
                    max = i + 1;
                } else {
                    max = (div(i - curr, 2).quot > max)?(div(i - curr, 2).quot):max;
                }
                curr = i;     
            }
        }
        max = (seats.size() - curr > max)?(seats.size() - curr):max;
        return max;
    }
};

int main() {
    Solution sl = Solution();
    std::vector<int> vct = {1,0,0,0,1,0,1};
    std::cout << sl.maxDistToClosest(vct);
    return 0;
}