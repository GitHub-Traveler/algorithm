#include <bits/stdc++.h>
#include <vector>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main()
{
	int t = 0;
	cin >> t;
	while (t--) {
		int n = 0;
		cin >> n;
		vector<i64> a(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		i64 gcd_arr = a[0];
		for (int i = 0; i < n; i++) {
			gcd_arr = gcd(gcd_arr, a[i]);
		}
		int result = 0;
		for (int i = 2; i < 10000; i++) {
			if (gcd(gcd_arr, i) == 1) {
				result = i;
				break;
			}
		}
		assert(result != 0);
		cout << result << "\n";
	}
}
