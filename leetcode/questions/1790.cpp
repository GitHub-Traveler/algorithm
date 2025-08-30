#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    bool areAlmostEqual(string s1, string s2) {
        char curr_char_s1 = ' ';
        char curr_char_s2 = ' ';
        bool flag = true;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (curr_char_s1 == ' ') {
                    curr_char_s1 = s1[i];
                    curr_char_s2 = s2[i];
                    flag = false;
                } else if (flag) {
                    return false;
                } else if (s1[i] == curr_char_s2 && s2[i] == curr_char_s1) {
                    flag = true;
                } else {
                    return false;
                }
            }
        }
        return flag;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    string s1 = "bank";
    string s2 = "kanb";
    cout << sol.areAlmostEqual(s1, s2) << endl;
    return 0;
}