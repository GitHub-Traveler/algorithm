#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int a = 0; a < t; a++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> map(n, vector<int>(m));
        int largest = INT_MIN;
        int row = -1;
        int col = -1;
        int row_alt = -1;
        int col_alt = -1;
        int count_largest = 0;
        pair<int, int> first_element;
        vector<pair<int, int>> largest_numbers;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j];
                largest = max(largest, map[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == largest) {
                    count_largest++;
                    largest_numbers.push_back(pair<int, int>(i, j));
                    if (row == -1 && col == -1) {
                        row = i;
                        col = j;
                    } else if (row != i && col != j) {
                        row_alt = i;
                        col_alt = j;
                    }
                }
            }
        }
        if (row_alt == -1 && col_alt == -1) {
            cout << largest - 1 << endl;
        } else {
            vector<pair<int, int>> settings = {pair<int, int>(row, col), pair<int, int>(row_alt, col),
                                               pair<int, int>(row, col_alt), pair<int, int>(row_alt, col_alt)};
            bool less = false;
            for (auto setting : settings) {
                bool less_2 = true;
                for (auto element : largest_numbers) {
                    if (element.first != setting.first && element.second != setting.second) {
                        less_2 = false;
                        break;
                    }
                }
                if (less_2) {
                    less = true;
                    cout << largest - 1 << endl;
                    break;
                }
            }
            if (!less) {
                cout << largest << endl;
            }
        }
    }
    return 0;
}
