#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> map(n, vector<int>(m, 0));
    int total_gold = 0;
    vector<pair<int, int>> places;
    vector<vector<int>> gold_grid(n, vector<int>(m, 0));
    for (int j = 0; j < n; j++) {
      for (int l = 0; l < m; l++) {
        char temp;
        cin >> temp;
        if (temp == '.') {
          map[j][l] = 0;
          places.push_back(pair<int, int>(j, l));
        } else if (temp == 'g') {
          map[j][l] = 2;
          total_gold++;
        } else if (temp == '#') {
          map[j][l] = 1;
        }
      }
    }
    for (int j = 0; j < n; j++) {
      for (int l = 0; l < m; l++) {
        if (j == 0 && l == 0) {
          gold_grid[j][l] = ((map[j][l] == 2) ? 1 : 0);
        } else if (j == 0) {
          gold_grid[j][l] = gold_grid[j][l - 1] + ((map[j][l] == 2) ? 1 : 0);
        } else if (l == 0) {
          gold_grid[j][l] = gold_grid[j - 1][l] + ((map[j][l] == 2) ? 1 : 0);
        } else {
          gold_grid[j][l] = gold_grid[j][l - 1] + gold_grid[j - 1][l] -
                            gold_grid[j - 1][l - 1] +
                            ((map[j][l] == 2) ? 1 : 0);
        }
      }
    }
    int min_lost_gold = INT_MAX;
    for (pair<int, int> place : places) {
      int x1 = max(0, place.first - k + 1);
      int x2 = min(place.first + k - 1, n - 1);
      int y1 = max(0, place.second - k + 1);
      int y2 = min(place.second + k - 1, m - 1);
      int val1 = (y1 > 0) ? gold_grid[x2][y1 - 1] : 0;
      int val2 = (x1 > 0) ? gold_grid[x1 - 1][y2] : 0;
      int val3 = (x1 > 0 && y1 > 0) ? gold_grid[x1 - 1][y1 - 1] : 0;

      int lost_gold = gold_grid[x2][y2] - val1 - val2 + val3;
      // cout << gold_grid[x2][y2] << " " << val1 << " " << val2 << " " << val3
      // << endl;
      min_lost_gold = min(lost_gold, min_lost_gold);
      // cout << min_lost_gold << endl;
    }
    cout << total_gold - min_lost_gold << endl;
  }
}
