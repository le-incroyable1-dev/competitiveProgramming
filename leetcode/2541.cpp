#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    long long minOperations(vector<int>& v1, vector<int>& v2, int k) {
        
        ll ans = 0;
        vector<ll> d;
        int n = v1.size();
        ll dsum = 0;

        if(k == 0){
            if(v1 == v2) return 0;
            else return -1;
        }
        
        for(int i = 0; i < n; ++i){
            ll dif = (ll)v2[i]-(ll)v1[i];

            if(abs(dif)%k != 0) return -1;
            else dif/=k;

            if(dif > 0) ans += dif;

            dsum += dif;
            d.push_back(dif);
        }

        if(dsum != 0) return -1;
        return ans;

    }
};
