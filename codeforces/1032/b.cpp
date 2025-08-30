#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        unordered_set<char> exist;
        bool val = false;
        exist.insert(str[0]);
        exist.insert(str[n - 1]);
        for (int j = 1; j < n - 1; j++) {
            // cout << str[j] << endl;
            if (exist.find(str[j]) == exist.end()) {
                exist.insert(str[j]);
            } else {
                cout << "Yes" << endl;
                val = true;
                break;
            }
        }
        if (!val) {
            cout << "No" << endl;
        }
    }
    return 0;
}
