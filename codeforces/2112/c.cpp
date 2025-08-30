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
        int n;
        cin >> n;
        vector<int> arr(n);
        int total = 0;
        vector<int> num_2_combinations(n);
        vector<int> num_3_combinations(n);
        if (n <= 3) {
            cout << 0 << "\n";
        }
        total += (n - 1) * (n - 2) / 2;
        int bob = arr[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }
}
