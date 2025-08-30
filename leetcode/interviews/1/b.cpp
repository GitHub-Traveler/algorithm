#include <bits/stdc++.h>
#include <vector>
using namespace std;
class solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths) {
        vector<int> result(n, 0);
        vector<vector<bool>> color(n, vector<bool>(4, true));
        vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < paths.size(); i++) {
            graph[paths[i][0] - 1].emplace_back(paths[i][1] - 1);
            graph[paths[i][1] - 1].emplace_back(paths[i][0] - 1);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < 5; j++) {
                if (color[i][j - 1]) {
                    result[i] = j;
                    for (int adj : graph[i]) {
                        color[adj][j - 1] = false;
                    }
                    break;
                }
            }
        }
        return result;
    }
};
