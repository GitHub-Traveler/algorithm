#include <bits/stdc++.h>
#include <vector>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
class Compare {
	bool operator()(const vector<int> &a, const vector<int> &b) const
	{
		return a[0] > b[0];
	}
};
int check_remaining_slot(vector<int> &a, int x, int dist)
{
	int result = 0;
	for (int i = 0; i < (int)a.size() + 1; i++) {
		if (i == 0) {
			result += max(0, a[0] + 1 - dist);
		} else if (i == (int)a.size()) {
			result += max(0, x - a[i - 1] + 1 - dist);
		} else {
			result += max(0, a[i] - a[i - 1] + 1 - 2 * dist);
		}
	}
	return result;
}
int main()
{
	int t = 0;
	cin >> t;
	while (t--) {
		int n = 0, k = 0, x = 0;
		cin >> n >> k >> x;
		vector<int> a(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int last_good_result = 0;
		int left = 1, right = 1e9;
		while (left <= right) {
			int mid = (right + left) / 2;
			if (check_remaining_slot(a, x, mid) >= k) {
				last_good_result = mid;
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		int total = 0;
		int flag = false;
		if (last_good_result == 0) {
			for (int i = 0; i < k; i++) {
				cout << i << " ";
			}
			cout << "\n";
			continue;
		}
		for (int i = 0; i < (int)a.size() + 1; i++) {
			if (i == 0) {
				int current =
					max(0, a[0] + 1 - last_good_result);
				if (current > 0) {
					for (int j = 0; j < current; j++) {
						cout << j << " ";
						total++;
						if (total == k) {
							flag = true;
							break;
						}
					}
				}
			} else if (i == (int)a.size()) {
				int current = max(0, x - a[i - 1] + 1 -
							     last_good_result);

				if (current > 0) {
					for (int j = x; j > x - current; j--) {
						cout << j << " ";
						total++;
						if (total == k) {
							flag = true;
							break;
						}
					}
				}
			} else {
				int current =
					max(0, a[i] - a[i - 1] + 1 -
						       2 * last_good_result);
				for (int j = a[i - 1] + last_good_result;
				     j <= a[i] - last_good_result; j++) {
					cout << j << " ";
					total++;
					if (total == k) {
						flag = true;
						break;
					}
				}
			}
			if (flag)
				break;
		}
		cout << "\n";
	}
}
