#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<pair<int, int>> graph(n);
    for (int i = 0; i < n; i++) {
        cin >> graph[i].first >> graph[i].second;
    }
}
