#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    vector<int> num_list = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    string getPermutation(int n, int k) {
        k--;
        string num = "";        
        while (n > 0) {
            div_t result = div(k, factorial(n - 1));
            num += num_list[result.quot];
            num_list.erase(num_list.begin() + result.quot);
            k = result.rem;
            n--;
        }
        return num;
    }
    int factorial(int n) {
        return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
    }
};