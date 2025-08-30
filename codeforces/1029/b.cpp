#include <iostream>
// #include <vector>
using namespace std;

int main() {
    int t;
    int n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        int counter = 0;
        if (n % 2) {
            for (int odd = 1; odd <= n; odd += 2) {
                cout << odd;
                cout << " ";
            }
            for (int even = n - 1; even > 0; even -= 2) {
                cout << even;
                cout << " ";
            }
        } else {
            for (int odd = 1; odd <= n; odd += 2) {
                cout << odd;
                cout << " ";
            }
            for (int even = n; even > 0; even -= 2) {
                cout << even;
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
