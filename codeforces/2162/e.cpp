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
		int n = 0, k = 0;
		cin >> n >> k;
		vector<int> a(n, 0);
		unordered_set<int> hashset;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			if (hashset.find(a[i]) == hashset.end()) {
				hashset.insert(a[i]);
			}
		}
		bool permutation = true;
		int first = -1;
		int counter_k = 0;
		for (int i = 1; i <= n; i++) {
			if (hashset.find(i) == hashset.end()) {
				permutation = false;
				first = i;
				break;
			}
		}
		if (permutation) {
			for (int i = 0; i < k; i++) {
				cout << a[i] << " ";
			}
		} else {
			int second = -1;
			cout << first << " ";
			counter_k++;
			if (k > 1) {
				for (int i = 1; i <= n; i++) {
					if (i != a[n - 1] && i != first) {
						second = i;
						cout << i << " ";
						counter_k++;
						break;
					}
				}
			}
			if (k > 2) {
				for (int i = 1; i <= n; i++) {
					if (i != second && i != first) {
						cout << i << " ";
						counter_k++;
					}
					if (counter_k == k) {
						break;
					}
				}
			}
		}
		cout << "\n";
	}
}
