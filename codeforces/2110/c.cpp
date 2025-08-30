#include <bits/stdc++.h>
#include <vector>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n = 0;
        cin >> n;
        vector<int> arr(n, -1);
        vector<pair<int, int>> obs(n, pair(0, 0));
        vector<pair<int, int>> new_obs(n, pair(0, 0));
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> obs[i].first >> obs[i].second;
        }
        int h = 0;
        bool impossible = false;
        new_obs[n - 1] = obs[n - 1];
        for (int i = n - 1; i > 0; i--) {
            if (arr[i] == -1) {
                int first_element = max(new_obs[i].first - 1, obs[i - 1].first);
                int second_element = min(new_obs[i].second, obs[i - 1].second);
                if (first_element > second_element) {
                    impossible = true;
                    break;
                }
                new_obs[i - 1] = pair(first_element, second_element);
            } else if (arr[i] == 0) {
                int first_element = max(new_obs[i].first, obs[i - 1].first);
                int second_element = min(new_obs[i].second, obs[i - 1].second);
                if (first_element > second_element) {
                    impossible = true;
                    break;
                }
                new_obs[i - 1] = pair(first_element, second_element);
            } else if (arr[i] == 1) {
                int first_element = max(new_obs[i].first - 1, obs[i - 1].first);
                int second_element = min(new_obs[i].second - 1, obs[i - 1].second);
                if (first_element > second_element) {
                    impossible = true;
                    break;
                }
                new_obs[i - 1] = pair(first_element, second_element);
            }
        }
        if (arr[0] == 0) {
            if (new_obs[0].first >= 1) {
                cout << -1 << "\n";
                continue;
            }
        }
        if (arr[0] == 1) {
            if (new_obs[0].first >= 2 || new_obs[0].second == 0) {
                cout << -1 << "\n";
                continue;
            }
        }
        if (arr[0] == -1) {
            if (new_obs[0].first >= 2) {
                cout << -1 << "\n";
                continue;
            }
        }
        // if (t == 0) {
        //     cout << "debug" << endl;
        //     for (int i = 0; i < n; i++) {
        //         cout << obs[i].first << " " << obs[i].second << "\n";
        //     }
        //     for (int i = 0; i < n; i++) {
        //         cout << new_obs[i].first << " " << new_obs[i].second << "\n";
        //     }
        // }
        if (impossible) {
            cout << -1 << "\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                cout << 0;
            } else if (arr[i] == 1) {
                cout << 1;
                h++;
            } else {
                if (h < new_obs[i].first) {
                    h++;
                    cout << 1;
                } else {
                    cout << 0;
                }
            }
            if (i != n - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}
