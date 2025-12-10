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
		unsigned int a = 0;
		unsigned int b = 0;
		cin >> a >> b;
		if (__builtin_clz(a) > __builtin_clz(b)) {
			cout << -1;
		} else if (a == b) {
			cout << 0;
		} else if ((a ^ b) <= a) {
			cout << 1 << '\n';
			cout << (a ^ b);
		} else {
			cout << 2 << "\n";
			unsigned int num1 = (1 << (31 - __builtin_clz(a)));
			unsigned int num2 = (a ^ b) - num1;
			assert((a ^ num1 ^ num2) == b);
			cout << num2 << "\n";
			cout << num1;
		}
		cout << "\n";
	}
}
