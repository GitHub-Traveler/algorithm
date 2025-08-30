#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> arr1(n);
        vector<int> arr2(n);
        vector<pair<int, int>> actions;
        for (int j = 0; j < n; j++) {
            cin >> arr1[j];
        }
        for (int j = 0; j < n; j++) {
            cin >> arr2[j];
        }
        // for (int j = 0; j < n; j++) {
        //     cout << "Content of arrays are: " << endl;
        //     cout << arr1[j] << arr2[j] << endl;
        // }
        bool sorted = false;
        while (!sorted) {
            sorted = true;
            for (int j = 0; j < n - 1; j++) {
                // cout << arr1[j] << arr2[j] << "cdmm" << endl;
                if (arr1[j] > arr1[j + 1]) {
                    sorted = false;
                    actions.emplace_back(1, j);
                    swap(arr1[j], arr1[j + 1]);
                }
                if (arr2[j] > arr2[j + 1]) {
                    sorted = false;
                    actions.emplace_back(2, j);
                    swap(arr2[j], arr2[j + 1]);
                }
            }
            for (int j = 0; j < n; j++) {
                if (arr1[j] > arr2[j]) {
                    sorted = false;
                    actions.emplace_back(3, j);
                    swap(arr1[j], arr2[j]);
                }
            }
        }
        cout << actions.size() << endl;
        for (auto action : actions) {
            cout << action.first << " " << action.second + 1 << "\n";
        }
    }
    return 0;
}
