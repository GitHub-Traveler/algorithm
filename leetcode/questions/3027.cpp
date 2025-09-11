#include <bits/stdc++.h>
#include <vector>
using namespace std;
using i64 = long long;
bool cmp(vector<int> &a, vector<int> &b) {
    if (a[1] != b[1]) {
        return a[1] < b[1];
    } else {
        return a[0] > b[0];
    }
}
class Solution {
public:
    int numberOfPairs(vector<vector<int>> &points) {
        int length = points.size();
        cout << length;
        int result = 0;
        sort(points.begin(), points.end(), cmp);
        for (int i = 0; i < length; i++) {
            for (int j = i; j < length; j++) {
                if (i == j)
                    continue;
                if (points[i][0] < points[j][0] || points[i][1] > points[j][1])
                    continue;
                bool increment = true;
                for (int k = i; k < j; k++) {
                    if (k == i || k == j)
                        continue;
                    if (points[i][0] >= points[k][0] && points[i][1] <= points[k][1] && points[j][0] <= points[k][0] &&
                        points[j][1] >= points[k][1]) {
                        increment = false;
                        break;
                    }
                }
                if (increment) {
                    result++;
                }
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    int n = 10, m = 15;
    long long result = s.flowerGame(n, m);
    return 0;
}