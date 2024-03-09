#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long p = 31;
const long long mod = 1e9 + 9;

class Solution {
public:
    
    ll res = 0;
    vector<vector<int>> g;
    vector<ll> subtree;
    
    ll initDfs(int i, int par, vector<int> &p){
        ll mx = 1LL * p[i];
        for(auto x : g[i]){
            if(x == par) continue;
            mx = max(mx, initDfs(x, i, p) + 1LL * p[i]);
        }

        subtree[i] = mx;
        return mx;
    }

    
    void rerootDfs(int i, int par, vector<int> &p,ll parval){
        int c1 = -1;
        ll m1 = 0; ll m2 = 0;

        for(auto x : g[i]){
            if(x == par) continue;
            if(subtree[x] > m1){
                m2 = m1; m1 = subtree[x];
                c1 = x;
            }
            else m2 = max(m2, subtree[x]); }
        res = max(res, max(m1, parval));

        //for carrying on parent value
        for(auto x : g[i]){
            if(x == par) continue;

            if(c1 == x) rerootDfs(x, i, p, 1LL * p[i] + max(m2, parval));
            else rerootDfs(x, i, p, 1LL * p[i] + max(m1, parval));
        }

        return;
    }

    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        g.clear(); g.resize(n);
        subtree.clear(); subtree.resize(n, 0LL);
        
        for(auto v : edges){ g[v[0]].push_back(v[1]); g[v[1]].push_back(v[0]); }
        
        initDfs(0, -1, price);
        rerootDfs(0, -1, price, 0);

        g.clear(); subtree.clear(); return res;
    }
};
