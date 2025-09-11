#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;
using i64 = long long;
class Solution {
public:
    i64 minOperations(vector<vector<int>> &queries) {
        int length = queries.size();
        // vector<i64> finalVal(32, 0);
        // for (long long i = 0; i < 32; i++) {
        //     finalVal[i] = pow(4LL, i) - 1LL;
        //     cout << finalVal[i] << "\n";
        // }
        i64 final_result = 0;
        for (int i = 0; i < length; i++) {
            int final_bit_left = 32 - __builtin_clz(queries[i][0]);
            int final_bit_right = 32 - __builtin_clz(queries[i][1]);
            int upper_left = (((final_bit_left) >> 1) << 1) + 1;
            int lower_right = (((final_bit_right + 1) >> 1) << 1) - 1;
            // cout << final_bit_left << " " << final_bit_right << "\n";
            // cout << upper_left << " " << lower_right << "\n";
            i64 result = 0;
            if (upper_left > lower_right)
                final_result += ((i64)(queries[i][1] - queries[i][0] + 1) * (i64)((final_bit_left + 1) / 2) + 1) / 2;
            else {
                result += (i64)((1 << (upper_left - 1)) - queries[i][0]) * (i64)((final_bit_left + 1) / 2);
                result += (i64)(queries[i][1] - (1 << (lower_right - 1)) + 1) * (i64)((final_bit_right + 1) / 2);
                for (int j = upper_left; j < lower_right; j += 2) {
                    result += (3LL * (1LL << (j - 1))) * ((i64)(j + 1) / 2);
                }
            }
            final_result += (result + 1) / 2;
        }
        // cout << final_result << "\n";
        return final_result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> queries = {{2, 6}};
    long long result = s.minOperations(queries);
    return 0;
}