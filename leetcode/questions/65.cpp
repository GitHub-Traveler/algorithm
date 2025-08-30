#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        
        for (int i = 1; i < n; i++)
            if (s[i] == 'e' or s[i] == 'E')
                if (i != n-1 || i != 0)
                    return isIntOrFloat(s.substr(0, i)) && isInteger(s.substr(i+1, n - i - 1));
                else
                    return false;
        return isIntOrFloat(s);

    }

    bool isIntOrFloat(string s) {
        return isInteger(s) || isFloat(s);
    }

    bool isInteger(string s) {
        if (s[0] != '-' && s[0] != '+' && !isdigit(s[0]))
            return false;
        if ((s[0] == '-' || s[0] == '+') && s.length() < 2)
            return false;
        for (int i = 1; i < s.length(); i++) {
            if (!isdigit(s[i]))
                return false;
        }
        return true;
    }

    bool isFloat(string s) {
        int n = s.length();
        if (n < 2)
            return false;
        bool dot = s[0] == '.';
        if (s[0] != '-' && s[0] != '+' && !isdigit(s[0]) && s[0] != '.')
            return false;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '.') {
                if (n <= 2 && !isdigit(s[0]))
                    return false;
                if (dot)
                    return false;
                else
                    dot = !dot;
            } else if (!isdigit(s[i]))
                return false;
        }
        return true;
    };

};