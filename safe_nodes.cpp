#include <bits/stdc++.h> 
using namespace std;

vector<bool> vis;
unordered_set<int> safe;

bool dfs(vector<vector<int>> &g, int i){
    bool res = false;
    vis[i] = true;

    for(auto u : g[i]){
        if(vis[u] && g[u].size() > 0 && (safe.find(u) == safe.end())){ res = true; continue; }
        res |= dfs(g, u);
    }
    
    if(res == false) safe.insert(i);
    return res;
}

vector<int> safeNodes(vector<vector<int>> &edges, int n, int e) {
    // Write your code here.
    
    safe.clear(); vis.clear();

    vector<vector<int>> g(n);
    vis.resize(n, false);
    for(auto v : edges) g[v[0]].push_back(v[1]);

    
    for(int u = 0; u < n; ++u){
        if(vis[u]) continue;
        dfs(g, u);
    }

    // for(auto val : safe) cout << val << " ";
    // cout << "\n";
    vector<int> ans;
    for(auto val : safe) ans.push_back(val);
    sort(ans.begin(), ans.end());
   
    return ans;
    
}
