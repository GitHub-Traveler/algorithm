#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int sum_from_input(int arr, int l, int r)
{
	cout << arr << " " << l << " " << r << endl;
	int result = 0;
	cin >> result;
	return result;
}

int main()
{
	int t = 0;
	cin >> t;
	while (t--) {
		int n = 0;
		cin >> n;
		int diff = sum_from_input(2, 1, n) - sum_from_input(1, 1, n);
		int left = 1, right = n;
		while (left < right) {
			int mid = (left + right) / 2;
			int current_diff = sum_from_input(2, 1, mid) -
					   sum_from_input(1, 1, mid);
			if (current_diff < diff) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		assert(left == right);
		int r = left + 1;
		left = 1, right = n;
		while (left < right) {
			int mid = ceil((float)(left + right) / 2);
			int current_diff = sum_from_input(2, mid, n) -
					   sum_from_input(1, mid, n);
			if (current_diff < diff) {
				right = mid - 1;
			} else {
				left = mid;
			}
		}
		assert(left == right);
		int l = right + 1;
		cout << "!" << " " << l << " " << r << endl;
	}
}
