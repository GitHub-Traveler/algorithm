#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
  public:
    int distinctEchoSubstrings(std::string str) {
        std::unordered_map<std::string, int> mapping;
        return 0;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    std::string test_text = "abcabcabc";
    std::cout << sol.distinctEchoSubstrings(test_text) << std::endl;
    return 0;
}
