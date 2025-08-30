#include <bits/stdc++.h>
#include <vector>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int n = 0;
        cin >> n;
        vector<int> optimalPath(1, 0);
        vector<int> longestPaths(n, 0);
        int maxLength = -1;
        for (int i = 0; i < n; i++) {
            cout << "?" << " " << i + 1 << " " << n;
            for (int j = 0; j < n; j++) {
                cout << " " << j + 1;
            }
            cout << endl;
            cin >> longestPaths[i];
            if (longestPaths[i] > maxLength) {
                maxLength = longestPaths[i];
                optimalPath[0] = i + 1;
            }
        }
        int currentLength = 1;
        while (currentLength < maxLength) {
            int currentNode = optimalPath[currentLength - 1];
            for (int i = 0; i < n; i++) {
                if (longestPaths[i] == (maxLength - currentLength)) {
                    cout << "?" << " " << currentNode << " " << 2 << " " << currentNode << " " << i + 1 << endl;
                    int temp = 0;
                    cin >> temp;
                    if (temp == 2) {
                        optimalPath.emplace_back(i + 1);
                        currentLength++;
                        break;
                    }
                }
            }
        }
        cout << "! " << optimalPath.size();
        for (int i : optimalPath) {
            cout << " " << i;
        }
        cout << endl;
    }
}
