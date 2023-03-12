#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int maxScore(vector<int>& v) {
        
        int n = v.size();
        
        vector<ll> vp, vn;
        int ans = 0;
        
        for(auto val : v){
            if(val > 0) vp.push_back(val);
            else vn.push_back(val);
        }
        
        
        
        sort(vp.begin(), vp.end());
        sort(vn.rbegin(), vn.rend());
        
        ll sum = 0;
        
        for(auto val : vp) sum += val, ++ans;
        for(auto val : vn){
            sum += val;
            if(sum > 0) ++ans;
        }
        
        return ans;
        
    }
};
