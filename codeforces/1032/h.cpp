#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> l(n);
        vector<int> r(n);
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> l[j] >> r[j];
            a[j] = min(l[j])
        }

        cout << endl;
    }
    return 0;
}
