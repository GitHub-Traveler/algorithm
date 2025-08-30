#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  int r, c, n, p;
  cin >> r >> c >> n >> p;
  vector<vector<int>> layout(r, vector<int>(c, 0));
  unordered_map<int, pair<int, int>> map;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> layout[i][j];
      if (layout[i][j]) {
        map[layout[i][j]] = pair<int, int>(i, j);
      }
    }
  }
  unordered_set<int> possible_place;
  for (auto val : map) {
    pair<int, int> current_place = val.second;
    int current_ppl = val.first;
    vector<pair<int, int>> place_around;
    if (current_place.first) {
      place_around.emplace_back(current_place.first - 1, current_place.second);
    }
    if (current_place.second) {
      place_around.emplace_back(current_place.first, current_place.second - 1);
    }
    if (current_place.first != r - 1) {
      place_around.emplace_back(current_place.first + 1, current_place.second);
    }
    if (current_place.second != c - 1) {
      place_around.emplace_back(current_place.first, current_place.second + 1);
    }
    for (auto adj : place_around) {
      if (int x = layout[adj.first][adj.second]) {
        int distance = abs(x - current_ppl);
        if (p < min(x, current_ppl)) {
          continue;
        } else if (p < max(x, current_ppl)) {
          if (p + distance <= n) {
            possible_place.insert(p + distance);
          }
        } else {
          if (p + distance <= n) {
            possible_place.insert(p + distance);
          }
          if (p - distance >= 1) {
            possible_place.insert(p - distance);
          }
        }
      }
    }
  }
  cout << possible_place.size() << "/" << n - 1 << endl;
  // for (auto element : possible_place) {
  //   cout << element << endl;
  // }
}
