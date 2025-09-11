#include <bits/stdc++.h>
#include <unordered_map>
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
        vector<int> b(n, 0);
        unordered_map<int, vector<int>> counter;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int current_element = 0;
        for (int i = 0; i < n; i++) {
            if (counter.find(b[i]) == counter.end()) {
                counter[b[i]] = vector<int>{i};
            } else {
                counter[b[i]].push_back(i);
            }
        }
        vector<int> result(n, 0);
        bool impossible = false;
        for (auto element : counter) {
            if ((int)element.second.size() % element.first != 0) {
                impossible = true;
                break;
            }
            for (int i = 0; i < element.second.size(); i++) {
                if (i % element.first == 0) {
                    current_element++;
                }
                result[element.second[i]] = current_element;
            }
        }
        if (impossible) {
            cout << -1 << "\n";
        } else {
            cout << result[0];
            for (int i = 1; i < n; i++) {
                cout << " " << result[i];
            }
            cout << "\n";
        }
    }
}
