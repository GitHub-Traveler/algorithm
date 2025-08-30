#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> graph(n + 1, vector<int>());
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            // cout << u << v << n << endl;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bool result = false;
        int start_node;
        for (int i = 1; i <= n; i++) {
            if (graph[i].size() == 2) {
                result = true;
                start_node = i;
                break;
            }
        }
        if (!result) {
            cout << "NO" << "\n";
        } else {
            // cout << "first node" << start_node << endl;
            cout << "YES" << "\n";
            vector<int> visited(n + 1, -1);
            queue<pair<int, bool>> bfs;
            bfs.emplace(start_node, true);
            while (!bfs.empty()) {
                auto current_node = bfs.front();
                if (current_node.second == true) {
                    visited[current_node.first] = 1;
                } else {
                    visited[current_node.first] = 0;
                }
                bfs.pop();
                if (current_node.first == start_node) {
                    bfs.emplace(graph[current_node.first][0], true);
                    bfs.emplace(graph[current_node.first][1], false);
                    // cout << "lol1" << endl;
                    cout << current_node.first << " " << graph[current_node.first][1] << "\n";
                    cout << graph[current_node.first][0] << " " << current_node.first << "\n";
                } else {
                    // cout << "lol2" << endl;
                    for (auto node : graph[current_node.first]) {
                        if (current_node.second && visited[node] == -1) {
                            bfs.emplace(node, false);
                            cout << current_node.first << " " << node << "\n";
                        } else if (!current_node.second && visited[node] == -1) {
                            bfs.emplace(node, true);
                            cout << node << " " << current_node.first << "\n";
                        }
                    }
                }
            }
        }
    }
}
