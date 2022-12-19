#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int, int>> s;
        int n = t.size();
        vector<int> ans(n, 0);

        for(int i = 0; i < n; ++i){
            int val = t[i];

            while(!s.empty() && s.top().first < val){
                pair<int, int> p = s.top();
                s.pop();
                ans[p.second] = i - p.second;
            }

            s.push(make_pair(t[i], i));
        }

        return ans;
    }
};
