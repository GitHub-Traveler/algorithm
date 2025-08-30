#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    const int MAXN = 5000 + 5;
    vector<vector<int>> dp_gcd(MAXN + 1, vector<int>(MAXN + 1));
    for (int x = 0; x < MAXN; x++) {
        dp_gcd[x][0] = dp_gcd[0][x] = dp_gcd[x][x] = x;
    }
    for (int x = 1; x < MAXN; x++) {
        for (int y = 1; y < x; y++) {
            dp_gcd[x][y] = dp_gcd[y][x] = dp_gcd[y][x % y];
        }
    }
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int max_a = INT_MIN;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int min_gcd = a[0];
        for (int i = 0; i < n; i++) {
            min_gcd = gcd(min_gcd, a[i]);
        }
        for (int i = 0; i < n; i++) {
            a[i] /= min_gcd;
            max_a = max(max_a, a[i]);
        }
        vector<int> dp(max_a + 1, 63);
        for (int i = 0; i < n; i++) {
            dp[a[i]] = 0;
        }

        for (int i = max_a; i > 0; i--) {
            for (int j = 0; j < n; j++) {
                int temp = a[j];
                dp[dp_gcd[i][temp]] = min(dp[dp_gcd[i][temp]], dp[i] + 1);
            }
        }
        if (dp[1] != 0) {
            cout << dp[1] + n - 1 << endl;
        } else {
            int result = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] > 1) {
                    result++;
                }
            }
            cout << result << endl;
        }
    }
}
