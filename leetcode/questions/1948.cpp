#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &path) {
        vector<vector<string>> final;
        return final;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    vector<vector<string>> path = {{"a"}, {"c"}, {"d"}, {"a", "b"}, {"c", "b"}, {"d", "a"}};
    vector<vector<string>> results = sol.deleteDuplicateFolder(path);
    for (auto vec : results) {
        for (auto str : vec) {
            cout << str << " ";
        }
        cout << "\n";
    }
    cout << endl;
    return 0;
}
