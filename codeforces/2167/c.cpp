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
		bool exist_odd = false;
		bool exist_even = false;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] % 2)
				exist_odd = true;
			else
				exist_even = true;
		}
		bool purity = exist_odd ^ exist_even;
		if (purity) {
			for (int i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
		} else {
			sort(a.begin(), a.end());
			for (int i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
		}
		cout << "\n";
	}
}
