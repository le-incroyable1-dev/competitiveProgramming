typedef pair<int, int> pii;
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& v) {
        
        vector<pii> vp;
        int n = v.size();
        for(int i = 0; i < n; ++i){
            vp.push_back(make_pair(v[i], i));
        }
        
        sort(vp.begin(), vp.end());
        
        int ans = INT_MAX;
        ans = min(ans, vp[n-1].first-vp[2].first);
        ans = min(ans, vp[n-3].first-vp[0].first);
        ans = min(ans, vp[n-2].first-vp[1].first);
        return ans;
        
    }
};
