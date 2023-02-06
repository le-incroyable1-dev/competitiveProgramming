#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {

    
private:
    
    void dijkstraop(int src, vector<ll> &v, vector<pair<int, int>> *g, int n){
        
        v[src] = 0;
        
        
        priority_queue<pair<ll, int>> pq;
        pq.push(make_pair(0, src));
        vector<bool> processed(n, false);
       
        while(!pq.empty()){
            auto [dist, val] = pq.top(); pq.pop();
            if(processed[val]) continue;
            processed[val] = true;
            
            for(auto [node, wt] : g[val]){
                if(v[node] > v[val] + wt){
                    v[node] = v[val] + wt;
                    pq.push(make_pair(-1*v[node], node));
                }
            }
            continue;
        }
        
        // cout << src << "\n";
        // for(auto val : v)
        //     cout << val << " ";
        
        // cout << "\n\n";
        
        return;
        
    }
    
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        
        vector<pair<int, int>> g[n], gopp[n];
        
        for(auto e : edges){
            g[e[0]].push_back(make_pair(e[1], e[2]));
            gopp[e[1]].push_back(make_pair(e[0], e[2]));
        }
        
        vector<ll> vs1(n, LLONG_MAX);
        vector<ll> vs2(n, LLONG_MAX);
        vector<ll> vd(n, LLONG_MAX);
        
        dijkstraop(src1, vs1, g, n);
        dijkstraop(src2, vs2, g, n);
        dijkstraop(dest, vd, gopp, n);
        
        ll ans = LLONG_MAX;
        
        for(int i = 0; i < n; ++i){       
            if(vs1[i] == LLONG_MAX || vs2[i] == LLONG_MAX || vd[i] == LLONG_MAX) continue;     
            ans = min(ans, vs1[i] + vs2[i] + vd[i]);
        }
        
        return (ans == LLONG_MAX ? -1 : ans);
    }
};
