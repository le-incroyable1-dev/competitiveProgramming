#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

ll c[101][101];

int build(ll a){
    ll res = 1;
    
    if(a <= 1) return res;
    
    ll h = (ll)log2(a+1);
    
    if(h <= 1) return res;
    
    ll m = (ll)pow(2, h);
    
    ll rem = a - (ll)pow(2, h) + 1;

    ll l, r;
    if(rem >= m/2) l = (ll)pow(2, h)-1;
    else l = rem + (ll)pow(2, h-1) - 1;
    
    r = max(0LL, (a-1LL)-l);
    
    ll ncl = c[a-1][l];
    
    (res *= ncl)%=mod;
    (res *= build(l))%=mod;
    (res *= build(r))%=mod;
    
    return (int)res;
}

int Solution::solve(int a) {
    
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= i; j++){
            if(i == j || j == 0){c[i][j] = 1;continue;}
            c[i][j] = (c[i-1][j] + c[i-1][j-1])%mod;
        }
    }
    
    int ans = build(a);    
    return ans;
    
}


