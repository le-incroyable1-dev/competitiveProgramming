#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

class Solution {
public:
    int sumOfPower(vector<int>& v) {
        
        ll res = 0; 
        sort(v.begin(), v.end());
        int n = v.size();

        ll save = 0;

        for(int i = 0; i < n; ++i){ (res += (ll)v[i]%mod * (ll)v[i]%mod * (ll)v[i]%mod)%=mod; }

        for(int i = 1; i < n; ++i){
            (save *= 2LL)%=mod;
            (save += (ll)v[i-1]%mod)%=mod;

            ll add = save;
            (add *= (ll)v[i]%mod * (ll)v[i]%mod)%=mod; 

            (res += add)%=mod;
        }

        if(res > INT_MAX) return INT_MAX;
        else return (int)res;
        
    }
};
