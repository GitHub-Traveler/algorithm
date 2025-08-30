#include <iostream>
#include <vector>
#include <bits/stdc++.h>
class Solution {
public:
    int bestTeamScore(std::vector<int>& scores, std::vector<int>& ages) {
        std::vector<std::pair<int, int>> lst;
        int len = scores.size();
        for (int i = 0; i < len; i++) {
            lst.push_back(std::make_pair(ages[i], scores[i]));
        };
        std::sort(lst.begin(), lst.end());
        int dp[len];
        int result = 0;
        for (int i = 0; i < len; i++) {
            dp[i] = lst[i].second;
            for (int j = 0; j < i; j++) {
                if (lst[i].second >= lst[j].second) {
                    dp[i] = std::max(dp[i], lst[i].second + dp[j]);
                }
            }
            result = std::max(result, dp[i]);
        }
        return result;
    }
};

int main() {
    Solution sl = Solution();
    std::vector<int> scores = {4,5,6,5};
    std::vector<int> ages = {2,1,2,1};
    std::cout << sl.bestTeamScore(scores, ages);
    return 0;
}