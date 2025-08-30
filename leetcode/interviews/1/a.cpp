#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string stringBitmask(string original, int bitmask) {
        int length = original.size();
        string newWord = "";
        for (int i = 0; i < length; i++) {
            if ((bitmask >> i) & 1) {
                newWord += original[i];
            }
        }
        return newWord;
    }
    int factorial(int n) {
        return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        unordered_set<string> hashset;
        int length = tiles.size();
        int total_result = 0;
        for (int i = 0; i < (1 << length); i++) {
            string newWord = stringBitmask(tiles, i);
            unordered_map<char, int> count;
            if (hashset.find(newWord) != hashset.end()) {
                continue;
            } else {
                hashset.emplace(newWord);
            }
            for (int j = 0; j < newWord.size(); j++) {
                if (count.find(newWord[j]) == count.end()) {
                    count[newWord[j]] = 1;
                } else {
                    count[newWord[j]]++;
                }
            }
            int counter = newWord.size();
            int result = 1;
            for (const auto &pair : count) {
                result *= (int)(factorial(counter) / (factorial(pair.second) * factorial(counter - pair.second)));
                counter -= pair.second;
            }
            total_result += result;
        }
        return total_result;
    }
};
