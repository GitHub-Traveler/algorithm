#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
bool compare(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int n = 0, m = 0;
        cin >> n >> m;
        vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < m; i++) {
            int u = 0, v = 0;
            cin >> u >> v;
            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }
        vector<int> min_time(n, -1);
        priority_queue<pair<int, int>> pq;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto current = pq.top();
            auto current_vertex = current.second;
            auto current_time = current.first;
            if (min_time[current_vertex] != -1) {
                min_time[current_vertex] = current_time;
            } else {
                continue;
            }
            pq.pop();
            int current_vertex_degree = graph[current_vertex].size();
            int current_remainder = current_time % current_vertex_degree;
            for (int i = 0; i < current_vertex_degree; i++) {
                pq.emplace(graph[current_vertex][i],
                           current_time + ((current_vertex_degree - i + current_remainder) % current_vertex_degree));
            }
        }
        cout << min_time[n - 1] << "\n";
    }
}
