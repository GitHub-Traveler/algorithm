#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  static bool function(pair<int, int> i, pair<int, int> j) {
    return i.second < j.second;
  }
  vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
    vector<pair<int, int>> num_pairs;
    for (int num : nums) {
      int current_num = num;
      int mapped_num = 0;
      int remaining = 0;
      int power = 0;
      do {
        remaining = current_num % 10;
        current_num = int(current_num / 10);
        mapped_num += mapping[remaining] * pow(10, power);
        power += 1;
      } while (current_num);
      pair<int, int> curr_pair = {num, mapped_num};
      num_pairs.push_back(curr_pair);
    }
    sort(num_pairs.begin(), num_pairs.end(), function);
    vector<int> final_result;
    for (pair<int, int> &pair : num_pairs) {
      final_result.push_back(pair.second);
    }
    return final_result;
  }
};

int main() {
  Solution sl = Solution();
  std::vector<int> mapping = {8, 9, 4, 0, 2, 1, 3, 5, 7, 6};
  std::vector<int> nums = {991, 338, 38};
  sl.sortJumbled(mapping, nums);
  return 0;
}
