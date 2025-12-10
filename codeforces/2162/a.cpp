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
		vector<int> a(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int maximum = 0;
		for (int i = 0; i < n; i++) {
			maximum = max(a[i], maximum);
		}
		cout << maximum << "\n";
	}
}
