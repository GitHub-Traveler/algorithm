#include <iostream>
#include <vector>

using namespace std;
int dfs(vector<int> &current_vector, vector<vector<int>> &edges, vector<int> &deg, int &max_depth_1, int &max_depth_2) {
    int current_node = current_vector[current_vector.size() - 1];
    if (edges[current_node].size() == 1 && current_node != 0) {
        if (max_depth_1 == -1) {
            max_depth_1 = deg[current_node];
        } else if (max_depth_2 == -1) {
            max_depth_2 = deg[current_node];
        }
        return 1;
    }
    int total = 0;
    for (int next_node : edges[current_node]) {
        if (current_vector.size() >= 2 && next_node == current_vector[current_vector.size() - 2]) {
            continue;
        }
        current_vector.emplace_back(next_node);
        if (deg[next_node] == -1) {
            deg[next_node] = deg[current_node] + 1;
        }
        total += dfs(current_vector, edges, deg, max_depth_1, max_depth_2);
        current_vector.pop_back();
    }
    return total;
};

int main() {
    int t;
    cin >> t;
    for (int a = 0; a < t; a++) {
        int n;
        cin >> n;
        vector<vector<int>> edges(n);
        vector<int> deg(n, -1);
        deg[0] = 1;
        vector<int> current(n);
        for (int i = 0; i < n - 1; i++) {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            edges[temp1 - 1].push_back(temp2 - 1);
            edges[temp2 - 1].push_back(temp1 - 1);
        }
        vector<int> current_vector = {0};
        int max_depth_1 = -1;
        int max_depth_2 = -1;
        int num_leaves = dfs(current_vector, edges, deg, max_depth_1, max_depth_2);
        if (num_leaves == 1) {
            int total = 1;
            const int divisor = static_cast<int>(1e9 + 7);
            for (int i = 0; i < n; i++) {
                total = total * 2;
                if (total > divisor) {
                    total -= divisor;
                }
            }
            cout << total << endl;
            continue;
        }
        if (num_leaves > 2) {
            cout << 0 << endl;
            continue;
        }
        if (num_leaves == 2) {
            int divide_node_depth;
            for (int i = 0; i < n; i++) {
                if (edges[i].size() == 3 || (i == 0 && edges[i].size() == 2)) {
                    divide_node_depth = deg[i];
                }
            }
            int total = 1;
            const int divisor = static_cast<int>(1e9 + 7);
            for (int i = 0; i < divide_node_depth; i++) {
                total = total * 2;
                if (total > divisor) {
                    total -= divisor;
                }
            }
            if (max_depth_1 == max_depth_2) {
                cout << total * 2 << endl;
                continue;
            } else {
                for (int i = 0; i < abs(max_depth_1 - max_depth_2) - 1; i++) {
                    total = total * 2;
                    if (total > divisor) {
                        total -= divisor;
                    }
                }
                int final_total = ((total * 2 % divisor) + (total % divisor)) % divisor;
                cout << final_total << endl;
                continue;
            }
        }
    }
}
