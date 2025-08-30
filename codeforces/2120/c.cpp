#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        long long m;
        cin >> n >> m;
        vector<long long> count(n + 1, -1);
        long long sum = n * (n + 1) / 2;
        if (sum < m || n > m) {
            cout << -1 << endl;
            continue;
        }
        long long root = -1;
        for (long long i = 1; i <= n; i++) {
            if (m >= n - i + 1) {
                count[i] = n - i + 1;
                if (i >= 2) {
                    count[i - 1] = 1;
                }
                m -= n - i + 1;
                if (m == 0) {
                    root = i;
                    break;
                }
            } else {
                root = i;
                count[i] = m;
                count[i - 1] -= m;
                break;
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     cout << count[i] << " ";
        // }
        // cout << "debug\n";
        cout << root << endl;
        for (long long i = root; i >= 1; i--) {
            if (i == root) {
                for (long long j = n - count[i] + 2; j <= n; j++) {
                    cout << i << " " << j << "\n";
                }
            } else if (i == root - 1) {
                for (long long j = root; j <= n - count[i + 1] + 1; j++) {
                    cout << i << " " << j << "\n";
                }
            } else {
                cout << i << " " << i + 1 << endl;
            }
        }
    }
}
