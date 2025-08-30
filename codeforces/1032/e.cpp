#include <iostream>
#include <string>
using namespace std;
int recursion(string left, string right) {
    if (left.size() == 1) {
        if (right[0] - left[0] == 0) {
            return 2;
        } else if (right[0] - left[0] == 1) {
            return 1;
        } else {
            return 0;
        }
    }
    if (left == right) {
        return left.size() * 2;
    } else {
        if (left[0] - right[0] == 0) {
            return 2 + recursion(left.substr(1, size(left) - 1), right.substr(1, right.size() - 1));
        } else if (right[0] - left[0] == 1) {
            int r1 = recursion(string('0', right.size() - 1), right.substr(1, right.size() - 1));
            int r2 = recursion(left.substr(1, left.size() - 1), string(left.size() - 1, '9'));
            return 1 + min(r2, r1);
        } else {
            return 0;
        }
    }
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string l, r;
        cin >> l >> r;
        int result = recursion(to_string(stoi(l) + 1), to_string(stoi(r) - 1));
        cout << result << endl;
    }
    return 0;
}
