#include <bits/stdc++.h>
#include <vector>
using namespace std;
using i64 = long long;
class Solution {
public:
    string sortVowels(string s) {
        int length = s.size();
        vector<char> vowels;
        for (int i = 0; i < length; i++) {
            if (tolower(s[i]) == 'a' || tolower(s[i]) == 'o' || tolower(s[i]) == 'i' || tolower(s[i]) == 'e' ||
                tolower(s[i]) == 'u') {
                vowels.emplace_back(s[i]);
            }
        }

        int counter = 0;
        std::ranges::sort(vowels.begin(), vowels.end());
        for (int i = 0; i < length; i++) {
            if (tolower(s[i]) == 'a' || tolower(s[i]) == 'o' || tolower(s[i]) == 'i' || tolower(s[i]) == 'e' ||
                tolower(s[i]) == 'u') {
                s[i] = vowels[counter];
                counter++;
            }
        }
        return s;
    }
};