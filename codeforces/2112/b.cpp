#include <bits/stdc++.h>
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
        int num_op = -1;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++) {
            if (i == 1) {
                if (abs(arr[i] - arr[i - 1]) <= 1) {
                    num_op = 0;
                    break;
                }
            }
            if (i > 1) {
                if (abs(arr[i] - arr[i - 1]) <= 1) {
                    num_op = 0;
                    break;
                }
                bool temp1 = arr[i] < arr[i - 1] && arr[i - 1] > arr[i - 2];
                bool temp2 = arr[i] > arr[i - 1] && arr[i - 1] < arr[i - 2];
                if (temp1 || temp2) {
                    num_op = 1;
                }
            }
            // cout << num_op << "here" << endl;
        }
        cout << num_op << endl;
    }
}
