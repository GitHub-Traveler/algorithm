#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a;
    cin >> a;
    for (int i = 0; i < a; i++) {
        int n, x;
        int start = -1;
        int end = -1;
        cin >> n >> x;
        vector<int> vect(n);
        for (int j = 0; j < n; j++) {
            cin >> vect[j];
            if (vect[j] && start == -1) {
                start = j;
            }
        }
        for (int j = n - 1; j > -1; j--) {
            if (vect[j]) {
                end = j;
                break;
            }
        }
        if (end != -1 && start != -1 && end - start < x) {
            // cout << end << start << endl;
            cout << "YES" << endl;
        } else {
            // cout << end << start << endl;
            cout << "NO" << endl;
        }
    }
    return 0;
}
