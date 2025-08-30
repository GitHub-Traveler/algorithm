#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int size = s.length();
        int i;
        st.push(0);
        for (i = 1; i < size; i++) {
            if (st.empty()) {
                st.push(i);
            }
            else if (s[st.top()] == '(' && s[i] == ')')
                st.pop();
            else
                st.push(i);
        }

        if (st.empty())
            return size;
        else {
            int max_size = size - 1 - st.top();
            int current = st.top();
            st.pop();
            while (!st.empty()) {
                if (max_size < current - st.top())
                    max_size = current - st.top();
                current = st.top();
                st.pop();
            }
            max_size = max(max_size, current);
            return max_size;
        }

    }
};

int main() {
    Solution sl = Solution();
    cout << sl.longestValidParentheses("())");
}