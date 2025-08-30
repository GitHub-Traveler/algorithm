#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        int counter = 1;
        string current = "";
        for (int i = 0; i < n; i++) {
            if (current.find(s[i]) != string::npos)
                current += s[i];
            else {
                counter += 1;
                current = "";
            }
        }
        return counter;
    }
};