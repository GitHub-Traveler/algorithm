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
		int n = 0, q = 0;
		cin >> n >> q;
		vector<int> a(q, 0);
		string s = "";
		cin >> s;
		for (int i = 0; i < q; i++) {
			cin >> a[i];
		}
		bool all_A = true;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'B') {
				all_A = false;
			}
		}
		if (all_A) {
			for (int i = 0; i < q; i++) {
				cout << a[i] << "\n";
			}
		} else {
			for (int i = 0; i < q; i++) {
				int count = 0;
				while (a[i] != 0) {
					int curr_index = (count % n);
					if (s[curr_index] == 'A') {
						a[i]--;
					} else {
						a[i] /= 2;
					}
					count++;
				}
				cout << count << "\n";
			}
		}
	}
}
