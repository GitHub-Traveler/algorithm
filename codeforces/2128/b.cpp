#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int n = 0;
        cin >> n;
        deque<int> arr;
        for (int i = 0; i < n; i++) {
            int temp = 0;
            cin >> temp;
            arr.push_back(temp);
        }
        int last_element = arr.back();
        cout << "R";
        arr.pop_back();
        bool increasing = true;
        while (!arr.empty()) {
            int head = arr.front();
            int tail = arr.back();
            if (increasing) {
                int temp_min = min(min(head, tail), last_element);
                int temp_max = max(max(head, tail), last_element);
                if (temp_min == last_element) {
                    if (temp_max == tail) {
                        cout << "R";
                        last_element = tail;
                        arr.pop_back();
                    } else {
                        cout << "L";
                        last_element = head;
                        arr.pop_front();
                    }
                } else {
                    if (temp_min == tail) {
                        cout << "R";
                        last_element = tail;
                        arr.pop_back();
                        increasing = false;
                    } else {
                        cout << "L";
                        last_element = head;
                        arr.pop_front();
                        increasing = false;
                    }
                }
            } else {
                int temp_min = min(min(head, tail), last_element);
                int temp_max = max(max(head, tail), last_element);
                if (temp_max == last_element) {
                    if (temp_min == tail) {
                        cout << "R";
                        last_element = tail;
                        arr.pop_back();
                    } else {
                        cout << "L";
                        last_element = head;
                        arr.pop_front();
                    }
                } else {
                    if (temp_max == tail) {
                        cout << "R";
                        last_element = tail;
                        arr.pop_back();
                        increasing = false;
                    } else {
                        cout << "L";
                        last_element = head;
                        arr.pop_front();
                        increasing = false;
                    }
                }
            }
        }
        cout << "\n";
    }
}
