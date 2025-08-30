#include <bits/stdc++.h>
#include <cmath>
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return log2(buckets)/log2(minutesToTest/minutesToDie + 1);
    }
};