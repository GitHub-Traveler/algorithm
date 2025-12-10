#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
class Solution {
public:
    bool doesAliceWin(string s) {
        int length = s.size();
        int counter = 0;
        for (int i = 0; i < length; i++) {
            char temp = tolower(s[i]);
            if (temp == 'a' || temp == 'o' || temp == 'i' || temp == 'e' || temp == 'u') {
                counter++;
            }
        }
        if (counter == 0) {
            return false;
        } else {
            return true;
        }
    }
};