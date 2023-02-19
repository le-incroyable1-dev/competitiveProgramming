#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007


class Solution {
public:
    
    vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    
    ll helper(int i, int mask, vector<int> &v, vector<vector<ll>> &dp){
        
        if(dp[i][mask] != -1) return dp[i][mask];
        if (i == v.size()) return dp[i][mask] = 1;
        
        ll ans = 0;
        
        int cur = mask;
        
        
        bool flag = true;
        
        for(int j = 0; j < 10; ++j){
            
            int num = v[i];
            int count = 0;
            
            while(num%prime[j] == 0){
                num /= prime[j];
                ++count;
            }
            
            if(count >= 2 || ((count==1) && (((1<<j)&mask) != 0))){
                flag = false;
                break;
            }
            
            if(count > 0) cur = cur|(1<<j);
            
        }
        
        (ans += helper(i+1, mask, v, dp))%=mod;
        
        if(flag) (ans += helper(i+1, cur, v, dp))%=mod;
        
        return dp[i][mask] = ans;
        
    }
    

    int squareFreeSubsets(vector<int>& v) {
        
        int n = v.size();
        ll ans = 0;
        
        vector<vector<ll>> dp(n+1, vector<ll>(1024+1, -1));
        
        ans = helper(0, 0, v, dp);
        ans--; //remove empty subset
        
        return ans;
        
    }
};
