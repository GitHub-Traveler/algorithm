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
		string t = "";
		cin >> s >> t;
		vector<int> nc(26, 0);
		for (int i = 0; i < n; i++) {
			int index = (int)s[i] - (int)'a';
			int index_2 = (int)t[i] - (int)'a';
			nc[index]++;
			nc[index_2]--;
		}
		bool flag = true;
		for (int i = 0; i < 26; i++) {
			if (nc[i] != 0) {
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}
