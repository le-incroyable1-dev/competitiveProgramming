#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    vector<int> *g;
    vector<int> vis;
    int nv = 0;
    

    void dfs(int i){
        vis[i] = 1;
        ++nv;

        for(auto v : g[i]){
            if(vis[v] != 0) continue;
            dfs(v);
        }

        return;
    }

    void dfs_c(int i, bool &c){
        
        vis[i] = 2;
        if(c == false) return;
        if(g[i].size() != nv-1){ c = false; return; }

        for(auto v : g[i]){
            if(vis[v] == 2) continue;
            dfs_c(v, c);
        }

        return;
    }

    int countCompleteComponents(int n, vector<vector<int>>& e) {
        vector<int> gr[n];
        for(auto v : e) gr[v[0]].push_back(v[1]), gr[v[1]].push_back(v[0]);
        g = gr;
        vis.resize(n, 0);
        
        int res = 0;
        for(int i = 0; i < n; ++i){
            
            if(vis[i] != 0) continue;
            
            dfs(i);
            
            //cout << nv << "\n";

            bool c = true;
            dfs_c(i, c);

            if(c) ++res;
            nv = 0;
        }

        return res;

        
    }
};
