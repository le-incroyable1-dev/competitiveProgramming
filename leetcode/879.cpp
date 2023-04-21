#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100
#define mod 1000000007

static auto _______ = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:

    vector<vector<vector<ll>>> dp;
    ll ways(int m, int profit, vector<pair<int, int>> &gp, int i, int minProfit, int mem){

        int n = gp.size();
        if(i == n) return dp[mem][profit][i] = (ll)(profit >= minProfit); 
        if(dp[mem][profit][i] != -1) return dp[mem][profit][i];
        

        ll res = 0LL;

        int g = gp[i].first;
        int p = gp[i].second;

        (res += ways(m, profit, gp, i+1, minProfit, mem))%=mod; 
        if(mem+g <= m)
        (res += ways(m, min(profit+p, minProfit), gp, i+1, minProfit, mem+g))%=mod;

        return dp[mem][profit][i] = res;
    }

    int profitableSchemes(int m, int minProfit, vector<int>& g, vector<int>& p) {

        int n = g.size();
        vector<pair<int, int>> gp;
        for(int i = 0; i < n; ++i) gp.emplace_back(g[i], p[i]);

        dp.resize(N+1, vector<vector<ll>>(N+1, vector<ll>(N+1, -1)));
        ll ans = ways(m, 0, gp, 0, minProfit, 0);

        if(ans > INT_MAX) return INT_MAX;
        else return (int)ans;
    }
};
