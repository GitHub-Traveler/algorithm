#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int a = 0; a < t; a++) {
        int n, k, q;
        cin >> n >> k;
        vector<long long> position(n);
        vector<int> delays(k);
        for (int i = 0; i < n; i++) {
            cin >> position[i];
        }
        for (int i = 0; i < k; i++) {
            cin >> delays[i];
        }
        cin >> q;
        vector<long long> starting(q);
        for (int i = 0; i < q; i++) {
            cin >> delays[i];
        }
    }
}
