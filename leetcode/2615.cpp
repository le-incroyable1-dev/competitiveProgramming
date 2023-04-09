#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    vector<long long> distance(vector<int>& v) {

        ll n = v.size();

        vector<ll> ans(n, -1);
        unordered_map<ll, vector<ll>> m;

        for(ll i = 0; i < n; ++i){
            m[v[i]].push_back(i);
        }

        for(auto [c, vc] : m){
            ll sz = vc.size();
            vector<ll> ls(sz, 0);
            vector<ll> rs(sz, 0);

            ll csum = 0;
            for(int i = 0; i < sz; ++i) csum += vc[i], ls[i] = csum;
            csum = 0;
            for(int i = sz-1; i >= 0; i--) csum += vc[i], rs[i] = csum;

            for(ll i = 0; i < sz; ++i){
                ll res = 0;
                res += (vc[i]*(i-0LL))-(ls[i]-vc[i]);
                res += (rs[i]-vc[i])-(vc[i]*(sz-1LL-i));

                ans[vc[i]] = res;
            }
            
            continue;

        }

        return ans;
        
    }
};
