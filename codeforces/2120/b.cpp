#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<pair<int, int>> place;
        vector<pair<int, int>> direction;
        int result = 0;

        for (int i = 0; i < n; i++) {
            int dx, dy, x, y;
            cin >> dx >> dy >> x >> y;
            place.emplace_back(x, y);
            direction.emplace_back(dx, dy);
            if (dx == dy && x == y) {
                result++;
            } else if (dx == -dy && x - s == -y) {
                result++;
            }
        }
        cout << result << "\n";
    }
}
