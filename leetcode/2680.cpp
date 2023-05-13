#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:


    ll solve(int i, vector<ll> &v, int k, vector<vector<ll>> &dp){
        
        ll val = 0;

        int n = v.size();
        if(dp[i][k] != -1LL) return dp[i][k];
        if(i == n) return dp[i][k] = 0LL;

        ll v1 = 0;
        ll v2 = 0;
        
        ll num = v[i];
        int k1 = k;
        
        while(k1 > 0){
            num *= 2LL;
            k1--;
            ll cur = 0; cur |= num;

            cur |= solve(i+1, v, k1, dp);
            v1 = max(v1, cur);
        }

        v2 |= v[i];
        v2 |= solve(i+1, v, k, dp);

        val = max(v1, v2);
        return dp[i][k] = val;
    }


    long long maximumOr(vector<int>& nums, int k) {
        cout << flush;
        ll res = 0;
        vector<vector<ll>> dp;
        int n = nums.size();
        vector<ll> v; for(auto val : nums) v.push_back((ll)val);
        
        dp.resize(n+2, vector<ll>(k+2, -1LL));

        res = solve(0, v, k, dp);
        return res;
        
    }
};
