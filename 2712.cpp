#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    long long minimumCost(string s) {
        
        ll n = s.length();
        if(n == 1) return 0LL;

        ll cost = 0;

        ll oc = 0;
        ll zc = 0;

        ll m = n/2;

    
        //check for one
        if(s[m-1] != '1') oc += m;
        for(int i = m-2; i >= 0; --i){
            if(s[i] != s[i+1]) oc += (ll)i+1LL;
        }

        if(s[m] != '1') oc += n-m;
        for(int i = m+1; i < n; ++i){
            if(s[i] != s[i-1]) oc += n-(ll)i;
        }


        //check for zero
        if(s[m-1] != '0') zc += m;
        for(int i = m-2; i >= 0; --i){
            if(s[i] != s[i+1]) zc += (ll)i+1LL;
        }

        if(s[m] != '0') zc += n-m;
        for(int i = m+1; i < n; ++i){
            if(s[i] != s[i-1]) zc += n-(ll)i;
        }


        //
        cost = min(oc, zc);
        
        
        return cost;
        
    }
};
