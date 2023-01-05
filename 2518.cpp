#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll powMod(ll n){
    ll res = 1;

    if(n == 0)
    return res;

    (res *= powMod(n/2))%=mod;
    (res *= powMod(n/2))%=mod;

    if(n%2 != 0)
    (res *= 2)%=mod;

    return res%mod;
}

class Solution {
public:


    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();

        if(n == 1) return 0;

        ll s = 0;
        for(auto val : nums)
        s+=val;

        if(s < 2*k)
        return 0;

        //int ans = 0;


        vector<vector<ll>> dp(n+1, vector<ll>(k+1, 0));
        dp[0][0] = 1;

        for(int i = 1; i <= n; ++i){
            for(int j = 0; j <= k; ++j){
                (dp[i][j] += dp[i-1][j])%=mod;

                if(j-nums[i-1] >= 0)
                (dp[i][j] += dp[i-1][j-nums[i-1]])%=mod;
            }
        }

        ll ways = 0;
        for(ll sum = 1; sum < k; ++sum){
            (ways += dp[n][sum])%=mod;
        }

        ways %= mod;
        cout << ways << "\n";
        ll ans = powMod(n);
        ans%=mod;
        ans -= 2;
        ans -= 2*ways;
      
        // ! when subtracting from a modulated number add mod again to ensure the number does not turn negative
        ans = (ans%mod + mod)%mod;
        // !

        if(ans > INT_MAX)
        return INT_MAX;
        else
        return (int)ans;

        
    }
};
