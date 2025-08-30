#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

i64 main() {
    i64 t;
    cin >> t;
    while (t--) {
        i64 n;
        cin >> n;
        i64 result = 0;
        vector<i64> a(n);
        vector<i64> b(n);
        unordered_set<i64> hashA;
        unordered_set<i64> hashB;
        for (i64 i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i64 i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (i64 i = n - 1; i >= 0; i--) {
            if (a[i] == b[i]) {
                result = i + 1;
                break;
            }
            if (hashA.find(b[i]) != hashA.end() || hashB.find(a[i]) != hashB.end()) {
                result = i + 1;
                break;
            }
            if (i > 0) {
                if (hashA.find(b[i - 1]) != hashA.end() || hashB.find(a[i - 1]) != hashB.end()) {
                    result = i;
                    break;
                }
            }
            hashA.insert(a[i]);
            hashB.insert(b[i]);
            swap(hashA, hashB);
        }
        cout << result << endl;
    }
}
