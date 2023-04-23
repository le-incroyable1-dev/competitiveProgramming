#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

class Solution {
public:


    vector<ll> dp;

    ll solve(int i, string &s, int &k){
        int n = s.length();

        if(dp[i] != -1) return dp[i];

        if(i == n) return dp[i] = 1LL;
        if(s[i] == '0') return dp[i] = 0LL;

        ll num = 0;
        ll ways = 0;
        for(int j = i; j < n; ++j){
            ll d = stoll(string(1, s[j]));
            num = num*10LL + d;

            if(num <= k) (ways += solve(j+1, s, k))%=mod;
            else break;
        }

        return dp[i] = ways%mod;
    }

    int numberOfArrays(string s, int k) {
        
        int n = s.length();
        dp.resize(n+2, -1);
        int res = solve(0, s, k);
        return res;

    }
};
