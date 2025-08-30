#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        priority_queue<char, vector<char>, greater<char>> pq;
        unordered_map<char, vector<int>> m;
        vector<bool> v(n, true);

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                char temp = pq.top(); // Get smallest char so far
                pq.pop();
                int last = m[temp].back(); // Get last occurrence index
                m[temp].pop_back();
                v[i] = false;    // Remove '*'
                v[last] = false; // Remove corresponding smallest char
            } else {
                pq.push(s[i]);
                m[s[i]].push_back(i);
            }
        }

        string result = "";
        for (int i = 0; i < n; i++) {
            if (v[i])
                result += s[i];
        }
        return result;
    }
};
int main() {
    Solution test = Solution();
    string s = "aaba*";
    cout << test.clearStars(s) << endl;
    return 0;
}
