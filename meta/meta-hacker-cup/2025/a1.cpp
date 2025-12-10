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
	for (int NUMBER = 0; NUMBER < t; NUMBER++) {
		int n = 0;
		cin >> n;
		vector<int> a(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int curr = 0;
		for (int i = 1; i < n; i++) {
			curr = max(curr, abs(a[i - 1] - a[i]));
		}
		cout << "Case #" << NUMBER + 1 << ": " << curr << "\n";
	}
}
