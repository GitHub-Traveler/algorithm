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
		int a = 0, b = 0, c = 0, d = 0;
		cin >> a >> b >> c >> d;
		if (a == b && b == c && c == d) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
