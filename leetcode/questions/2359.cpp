#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int closestMeetingNode(vector<int> &edges, int node1, int node2) {
    vector<int> distance1(edges.size(), -1);
    vector<int> distance2(edges.size(), -1);
    distance1[node1] = 0;
    distance2[node2] = 0;
    int current_node = node1;
    do {
      int next_node = edges[current_node];
      if (next_node == -1 || distance1[next_node] != -1) {
        break;
      }
      distance1[next_node] = distance1[current_node] + 1;
      current_node = next_node;
    } while (current_node != node1);

    current_node = node2;
    do {
      int next_node = edges[current_node];
      if (next_node == -1 || distance2[next_node] != -1) {
        break;
      }
      distance2[next_node] = distance2[current_node] + 1;
      current_node = next_node;
    } while (current_node != node2);

    int min_val = INT_MAX;
    int final_node = -1;
    for (int i = 0; i < edges.size(); i++) {
      if (distance1[i] != -1 && distance2[i] != -1) {
        if (min_val > max(distance1[i], distance2[i])) {
          min_val = max(distance1[i], distance2[i]);
          final_node = i;
        }
      }
    }
    return final_node;
  }
};

int main() {
  Solution test = Solution();
  vector<int> edges = {2, 2, 3, 1};
  int node1 = 0;
  int node2 = 1;
  int sol = test.closestMeetingNode(edges, node1, node2);
  cout << sol << endl;
  return 0;
}
