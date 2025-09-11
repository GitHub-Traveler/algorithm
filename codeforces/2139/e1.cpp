#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        i64 n = 0, k = 0;
        cin >> n >> k;
        vector<i64> p(n, 0);
        queue<int> que;
        vector<vector<int>> children(n, vector<int>());
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            children[p[i]].emplace_back(i);
        }
        vector<int> deg(n, 0);
        deg[0] = 1;
        que.emplace(0);
        int max_deg = 1;
        while (!que.empty()) {
            int curr = que.front();
            que.pop();
            for (auto child : children[curr]) {
                deg[child] = deg[curr] + 1;
                if (deg[child] > max_deg && ((int)children[child].size() == 0)) {
                    max_deg = deg[child];
                }
                que.emplace(child);
            }
        }
        vector<int> num_deg(max_deg, 0);
        for (int i = 0; i < n; i++) {
            if ((deg[i] - 1) < max_deg)
                num_deg[deg[i] - 1]++;
        }
        sort(num_deg.begin(), num_deg.end());
    }
}
