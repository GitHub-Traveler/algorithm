#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
        bool bl = (l1 == l2 && l2 == l3 && (b1 + b2 + b3) == l1);
        bool bb = (b1 == b2 && b2 == b3 && (l1 + l2 + l3) == b1);
        bool c1 = (l1 + l2 == l3 && b1 == b2 && b1 + b3 == l3);
        bool c2 = (l1 + l3 == l2 && b1 == b3 && b1 + b2 == l2);
        bool c3 = (l2 + l3 == l1 && b2 == b3 && b2 + b1 == l2);
        bool d1 = (b1 + b2 == b3 && l1 == l2 && l1 + l3 == b3);
        bool d2 = (b1 + b3 == b2 && l1 == l3 && l1 + l2 == b2);
        bool d3 = (b2 + b3 == b1 && l2 == l3 && l2 + l1 == b1);
        bool final = bl || bb || c1 || c2 || c3 || d1 || d2 || d3;
        if (final) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}
