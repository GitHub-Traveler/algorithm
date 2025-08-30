#include <iostream>
#include <unordered_set>
#include <vector>
// #include <vector>
using namespace std;

int main() {
    int t;
    int n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> arr(n);
        unordered_set<int> last_occurence;
        unordered_set<int> next_occurence;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        int ans = 1;
        last_occurence.insert(arr[0]);
        for (int i = 1; i < n; i++) {
            next_occurence.insert(arr[i]);
            last_occurence.erase(arr[i]);
            if (!last_occurence.size()) {
                last_occurence = next_occurence;
                next_occurence = unordered_set<int>();
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
