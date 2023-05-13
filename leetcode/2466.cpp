#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    const int N = 1e5;
    vector<ll> dp;

    ll ways(int &a, int &b, int s){
        ll w = 0;

        if(dp[s] != -1) return dp[s];
        if(s == 0LL) return dp[s] = 1LL;
        
        if(s-a >= 0) (w += ways(a, b, s-a))%=mod;
        if(s-b >= 0) (w += ways(a, b, s-b))%=mod;

        return dp[s] = w;
    }

    int countGoodStrings(int low, int high, int a, int b) {
        dp.resize(N+1, -1);
        ll res = ways(a, b, high);

        ll sum = 0;
        for(int i = low; i <= high; ++i) (sum += dp[i])%=mod;
        
        return (int)sum;
    }
};
