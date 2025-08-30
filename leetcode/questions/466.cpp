#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int idx_2 = 0, counter = 0;
        int size_s1 = s1.length(), size_s2 = s2.length();
        for (int i = 0; i < n1; i++)
            for (int j = 0; j < size_s1; j++) {
                if (s1[j] == s2[idx_2])
                    idx_2++;
                if (idx_2 == size_s2) {
                    counter++;
                    idx_2 = 0;
                }
            }
        return floor(counter / n2);
    }
};