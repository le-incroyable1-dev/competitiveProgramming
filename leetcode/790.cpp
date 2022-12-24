#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 1000
#define ll long long

class Solution {
public:

    int numTilings(int n) {

        vector<vector<ll>> dp(N+1, vector<ll>(2, 0));
        dp[0][0] = 1;
        dp[0][1] = 1;

        dp[1][0] = 0;
        dp[1][1] = 1;

        dp[2][0] = 2;
        dp[2][1] = 2;

        for(int i = 3; i <= n; ++i){
            (dp[i][0] += dp[i-1][0] + 2*dp[i-2][1])%=mod;
            (dp[i][1] += dp[i-1][0] + dp[i-1][1] + dp[i-2][1])%=mod;
        } 

        dp[n][1] %= mod;
        
        if(dp[n][1] > INT_MAX)
        return INT_MAX;
        
        int res = (int)(dp[n][1]);
        return res;
    }

   
};
