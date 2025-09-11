#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
using i64 = long long;
class Solution {
public:
    static vector<int> getNoZeroIntegers(int n) {
        string a;
        string b;
        for (int i = 1; i < n; i++) {
            a = to_string(i);
            b = to_string(n - i);
            bool correct = true;
            for (char j : a) {
                if (j == '0') {
                    correct = false;
                }
            }
            for (char j : b) {
                if (j == '0') {
                    correct = false;
                }
            }
            if (correct) {
                return {stoi(a), stoi(b)};
            }
        }
        return {-1};
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    int n = 10, m = 15;
    long long result = s.flowerGame(n, m);
    return 0;
}