#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks) {
        auto cmp = [](pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first) {
                return a.second > b.second;
            } else {
                return a.first > b.first;
            }
        };
        auto cmp_completion = [](tuple<int, int, int> a, tuple<int, int, int> b) {
            return get<0>(a) > get<0>(b);
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp_completion)>
            pq_completion(cmp_completion);

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        int num_tasks = tasks.size();
        int num_servers = servers.size();
        vector<int> assignVector(num_tasks);
        for (int i = 0; i < num_servers; i++) {
            pq.push({servers[i], i});
        };
        int current_time = 0;
        for (int j = 0; j < num_tasks; j++) {
            if (pq.empty()) {
                tuple<int, int, int> earliest_server = pq_completion.top();
                pq_completion.pop();
                pq.push({get<1>(earliest_server), get<2>(earliest_server)});
                current_time = get<0>(earliest_server);
                while (!pq_completion.empty() && current_time == get<0>(pq_completion.top())) {
                    tuple<int, int, int> next_free_server = pq_completion.top();
                    pq_completion.pop();
                    pq.push({get<1>(next_free_server), get<2>(next_free_server)});
                }
            } else {
                while (!pq_completion.empty() && current_time >= get<0>(pq_completion.top())) {
                    tuple<int, int, int> next_free_server = pq_completion.top();
                    pq_completion.pop();
                    pq.push({get<1>(next_free_server), get<2>(next_free_server)});
                }
            }
            pair<int, int> next_input = pq.top();
            assignVector[j] = next_input.second;
            pq.pop();
            pq_completion.push(
                make_tuple(current_time + tasks[j], next_input.first, next_input.second));
            current_time = max(current_time, j + 1);
        }
        return assignVector;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    vector<int> servers = {3, 3, 2};
    vector<int> tasks = {1, 2, 3, 2, 1, 2};
    vector<int> results = sol.assignTasks(servers, tasks);
    for (int num : results) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}