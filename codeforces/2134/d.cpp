#include <bits/stdc++.h>
#include <vector>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
void dfs(vector<vector<int>> &graph, vector<int> &current_longest_path, vector<int> &current_path) {
    // cout << "current path size: " << current_path.size() << "\n";
    // cout << "current node: " << current_path[current_path.size() - 1] + 1 << "\n";
    int current_node = current_path[current_path.size() - 1];
    if (graph[current_node].size() == 1 && current_path.size() > 1) {
        if (current_path.size() > current_longest_path.size()) {
            current_longest_path = current_path;
        }
        return;
    }

    for (int node : graph[current_node]) {
        if (current_path.size() != 1) {
            if (current_path[current_path.size() - 2] == node)
                continue;
        }
        current_path.emplace_back(node);
        dfs(graph, current_longest_path, current_path);
        current_path.pop_back();
    }
    // for (int i = 0; i < current_longest_path.size(); i++) {
    //     cout << current_longest_path[i] << ' ';
    // }
    // cout << "\n";
    return;
}
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int n = 0;
        cin >> n;
        vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < n - 1; i++) {
            int u = 0, v = 0;
            cin >> u >> v;
            graph[u - 1].emplace_back(v - 1);
            graph[v - 1].emplace_back(u - 1);
        }
        vector<int> current_path = {0};
        vector<int> current_longest_path = {0};
        dfs(graph, current_longest_path, current_path);

        vector<int> current_diameter = {current_longest_path[current_longest_path.size() - 1]};
        vector<int> current_longest_diameter = {current_longest_path[current_longest_path.size() - 1]};
        // for (int i = 0; i < current_longest_diameter.size(); i++) {
        //     cout << current_longest_diameter[i] << " ";
        // }
        // cout << "\n";

        dfs(graph, current_longest_diameter, current_diameter);
        // cout << "debug: ";
        // for (int i = 0; i < current_longest_diameter.size(); i++) {
        //     cout << current_longest_diameter[i] + 1 << " ";
        // }
        // cout << "\n";
        int diameter = current_longest_diameter.size();
        bool path_true = true;
        for (int i = 0; i < diameter; i++) {
            if (graph[current_longest_diameter[i]].size() >= 3) {
                path_true = false;
                int third_vertex = -1;
                for (int node : graph[current_longest_diameter[i]]) {
                    if (node != current_longest_diameter[i - 1] && node != current_longest_diameter[i + 1]) {
                        third_vertex = node;
                        break;
                    }
                }
                cout << current_longest_diameter[i - 1] + 1 << " " << current_longest_diameter[i] + 1 << " "
                     << third_vertex + 1 << "\n";
                break;
            }
        }
        if (path_true) {
            cout << "-1" << "\n";
        }
    }
}
