#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {

        i64 num1l = (i64)num1;
        i64 num2l = (i64)num2;
        for (i64 i = 1; i <= 64; i++) {
            i64 remaining = num1 - num2 * i;
            if (remaining < i)
                return -1;
            if (__builtin_popcountll(remaining) < i)
                return i;
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    int n = 10, m = 15;
    long long result = s.flowerGame(n, m);
    return 0;
}