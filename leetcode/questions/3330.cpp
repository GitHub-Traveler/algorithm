#include <string>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1;
        char currentChar = ' ';
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == currentChar) {
                count++;
            } else {
                currentChar = word[i];
            }
        }
        return count;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    string str = "abbccc";
    s.possibleStringCount(str);
    return 0;
}
