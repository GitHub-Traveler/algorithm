#include <bits/stdc++.h>
#include <vector>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

bool query(int i, int x)
{
	cout << "? " << i << " " << x << endl;
	int result = 0;
	cin >> result;
	return result;
}

void submit(int x)
{
	cout << "! " << x << endl;
	return;
}

int main()
{
	int t = 0;
	cin >> t;
	while (t--) {
		int n = 0;
		cin >> n;
		vector<int> deleted(n, 0);
		int remaining = n;
		int current_number = 0;
		int current_bit = 0;
		while (remaining != 1) {
			int x = (1 << current_bit);
			int current_one_number = current_number + x;
			int count_zero = 0;
			int count_one = 0;
			for (int i = 0; i < n; i++) {
				if (((i + 1) & current_one_number) ==
				    current_one_number)
					count_one++;
				else
					count_zero++;
			}
			for (int i = 0; i < n - 1; i++) {
				if (!deleted[i]) {
					bool temp_result = query(
						i + 1, current_one_number);
					if (temp_result == current_one_number)
						count_one--;
					else
						count_zero--;
				}
			}
			assert((count_one ^ count_zero) == 1);
			if (count_one == 0) {
				for (int i = 0; i < n; i++) {
					if (((i + 1) & current_one_number) ==
					    current_one_number) {
						deleted[i] = 1;
						remaining--;
					}
				}
			} else if (count_zero == 0) {
				for (int i = 0; i < n; i++) {
					if (((i + 1) & current_one_number) !=
					    current_one_number) {
						deleted[i] = 1;
						remaining--;
					}
				}
				current_number = current_one_number;
			}
			current_bit++;
		}
		for (int i = 0; i < n; i++) {
			if (!deleted[i]) {
				submit(i + 1);
				break;
			}
		}
	}
}
