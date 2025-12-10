#include <bits/stdc++.h>
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
		if (n % 2 == 0) {
			cout << (1 + (n - 4) / 2) << "\n";
		} else {
			cout << (1 + (n - 3) / 2) << "\n";
		}
	}
}
