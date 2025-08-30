// #include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    i64 t = 0;
    cin >> t;
    while (t--) {
        i64 n = 0;
        cin >> n;
        vector<i64> danger(n, 0);
        vector<i64> threat(n, 0);
        vector<i64> reverse_threat(n, 0);
        queue<pair<i64, i64>> q;
        vector<vector<i64>> edges(n, vector<i64>(0));
        for (i64 i = 0; i < n; i++) {
            cin >> danger[i];
        }
        for (i64 i = 0; i < n - 1; i++) {
            i64 temp1 = 0, temp2 = 0;
            cin >> temp1 >> temp2;
            edges[temp1 - 1].emplace_back(temp2 - 1);
            edges[temp2 - 1].emplace_back(temp1 - 1);
        }
        i64 root = 0;
        threat[0] = danger[0];
        reverse_threat[0] = 0;
        for (auto child : edges[0]) {
            q.emplace(child, 0);
        }
        while (!q.empty()) {
            auto next_node = q.front();
            q.pop();
            i64 current_node = next_node.first;
            i64 parent_node = next_node.second;
            threat[current_node] = max(danger[current_node], danger[current_node] - reverse_threat[parent_node]);
            reverse_threat[current_node] = min(danger[current_node], danger[current_node] - threat[parent_node]);
            for (auto node : edges[current_node]) {
                if (node != parent_node) {
                    q.emplace(node, current_node);
                }
            }
        }
        for (i64 i = 0; i < n - 1; i++) {
            cout << threat[i] << " ";
        }
        cout << threat[n - 1] << "\n";
    }
}
