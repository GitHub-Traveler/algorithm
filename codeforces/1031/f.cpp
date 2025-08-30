#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<int> vec1(n);
    vector<int> vec2(n);
    for (int j = 0; j < n; j++) {
      cin >> vec1[j];
    }
    for (int j = 0; j < n; j++) {
      cin >> vec2[j];
    }
    unordered_set<int> hash1;
    unordered_set<int> hash2;
    int total = 0;
    for (int j = 0; j < n; j++) {
      cin >> vec2[j];
    }
  }
}
