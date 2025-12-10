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
		string s = "";
		cin >> s;
		vector<int> indexes;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				indexes.emplace_back(i);
			}
		}
		cout << indexes.size() << "\n";
		for (int i : indexes) {
			cout << i + 1 << " ";
		}
		cout << "\n";
	}
}
