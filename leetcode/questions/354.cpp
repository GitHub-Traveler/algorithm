#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return b[1] < a[1];
        else
            return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> lis;
        int i, j, n = envelopes.size();
        for(i=0; i<n; i++){
            auto it = lower_bound(lis.begin(), lis.end(), envelopes[i][1]);
            if(it==lis.end()){lis.push_back(envelopes[i][1]);}
            else{
                *it = envelopes[i][1];
            }
        }
        return lis.size();
    }
};