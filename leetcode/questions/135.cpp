#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    vector<int> arr(n);
    int streak = 0;
    arr[0] = 1;
    for (int i = 1; i < n; i++) {
      if (ratings[i] > ratings[i - 1]) {
        arr[i] = arr[i - 1] + 1;
      } else {
        arr[i] = 1;
      }
    }
    arr[n - 1] = max(1, arr[n - 1]);
    for (int i = n - 2; i > -1; i--) {
      if (ratings[i] > ratings[i + 1]) {
        arr[i] = max(arr[i], arr[i + 1] + 1);
      } else {
        arr[i] = max(arr[i], 1);
      }
    }
    int sum = accumulate(arr.begin(), arr.end(), 0);
    return sum;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  vector<int> test_vector = {1, 2, 2};
  cout << sol.candy(test_vector) << endl;
  return 0;
}
