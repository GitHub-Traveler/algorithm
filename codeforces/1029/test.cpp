#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

map<pair<int, vector<int>>, int> memo;

int dp(int start_idx, const vector<int> &arr, const set<int> &required_set) {
    int n = arr.size();

    if (start_idx == n) {
        return 0;
    }

    // Convert required_set to vector for memoization key
    vector<int> required_vec(required_set.begin(), required_set.end());
    pair<int, vector<int>> key = {start_idx, required_vec};

    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    int max_segments = 0;
    set<int> current_elements;

    // Try all possible ending positions for current segment
    for (int end_idx = start_idx; end_idx < n; end_idx++) {
        current_elements.insert(arr[end_idx]);

        // Check if current segment contains all required elements from previous segment
        bool contains_all_required = true;
        for (int elem : required_set) {
            if (current_elements.find(elem) == current_elements.end()) {
                contains_all_required = false;
                break;
            }
        }

        if (!contains_all_required) {
            continue;
        }

        // If this is the last position, we can end here
        if (end_idx == n - 1) {
            max_segments = max(max_segments, 1);
            continue;
        }

        // Check if we can form next segment (remaining elements must contain all current elements)
        set<int> remaining_elements;
        for (int i = end_idx + 1; i < n; i++) {
            remaining_elements.insert(arr[i]);
        }

        bool can_continue = true;
        for (int elem : current_elements) {
            if (remaining_elements.find(elem) == remaining_elements.end()) {
                can_continue = false;
                break;
            }
        }

        if (can_continue) {
            // This segment is valid, recurse for remaining array
            int segments_after = dp(end_idx + 1, arr, current_elements);
            max_segments = max(max_segments, 1 + segments_after);
        }
    }

    memo[key] = max_segments;
    return max_segments;
}

int solve_cool_partition(const vector<int> &arr) {
    memo.clear();
    set<int> empty_set;
    return dp(0, arr, empty_set);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int result = solve_cool_partition(arr);
        cout << result << "\n";
    }

    return 0;
}
