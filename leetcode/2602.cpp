#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    vector<long long> minOperations(vector<int>& v, vector<int>& queries) {
        
        sort(v.begin(), v.end());
        ll n = v.size();
        vector<ll> vp;
        ll sum = 0;
        for(auto val : v) sum += val, vp.push_back(sum);
        vector<ll> ans;
        
        for(auto q : queries){
            
            ll res = 0;
            
            ll i1 = lower_bound(v.begin(), v.end(), q) - v.begin();
            ll sum1;
            if(i1 == 0) sum1 = -1;
            else sum1 = vp[i1-1];
            
            if(sum1 != -1){
                res += (i1)*(ll)q - sum1;
            }
            
            
            ll i2 = upper_bound(v.begin(), v.end(), q) - v.begin();
            ll sum2 = 0;
            if(i2 == n) sum2 = -1;
            else sum2 = vp[n-1] - vp[i2] + v[i2];
            
            if(sum2 != -1){
                res += sum2 - (n-i2)*(ll)q;
            }
            
            
            ans.push_back(res);
            
        }
        
        return ans;
        
        
    }
};
