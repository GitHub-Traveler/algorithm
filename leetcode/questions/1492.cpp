#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        double cap = sqrt(n);
        int counter = 0;
        vector<int> next;
        for (int i = 1; i <= cap; i++)
            if (n % i == 0) {
                counter++;
                if (i != (int) n/i)
                    next.push_back(n/i);
                if (counter == k)
                    return i;
            }
            return (k - counter <= next.size())?next[next.size() - (k - counter)]:-1;
    }
};