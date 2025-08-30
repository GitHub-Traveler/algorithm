#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, s;
    cin >> n >> s;
    int low = INT_MAX;
    int high = INT_MIN;
    vector<int> vect(n);
    for (int j = 0; j < n; j++) {
      cin >> vect[j];
      low = min(low, vect[j]);
      high = max(high, vect[j]);
    }
    int dist = min(abs(low - s), abs(high - s));
    int result = high - low + dist;
    cout << result << endl;
  }
}
