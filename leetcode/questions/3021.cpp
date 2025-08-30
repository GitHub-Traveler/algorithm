#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
class Solution {
public:
    long long flowerGame(int n, int m) {
        i64 n_even = n / 2;
        i64 n_odd = n - n_even;
        i64 m_even = m / 2;
        i64 m_odd = m - m_even;
        return (n_even * m_odd) + (n_odd * m_even);
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    int n = 10, m = 15;
    long long result = s.flowerGame(n, m);
    return 0;
}