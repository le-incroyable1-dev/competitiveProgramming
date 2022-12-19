#include <bits/stdc++.h>
using namespace std;

//solution assuming graph is connected, iterate over all components for a disconnected graph
class Solution {
public:

    int leaf = 0;
    void findALeaf(vector<int> *adj, vector<bool> &vis, int node){

        if(leaf != 0)
        return;

        if(adj[node].size() == 1){
            leaf = node;
            return;
        }

        vis[node] = true;

        for(auto val : adj[node]){
            if(!vis[val]){
                findALeaf(adj, vis, val);
            }
        }

        return;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        int ans = 0;

        vector<int> adj[n+1];
        for(auto v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        
        unordered_map<int, int> c;

        vector<bool> vis(n+1, false);
        vis[0] = true;
        queue<pair<int, int>> q;
        findALeaf(adj, vis, 1);
        if(leaf == 0)
        leaf = 1;
        
        q.push(make_pair(leaf, 1));
        c[leaf] = 1;

        for(int i = 0; i <= n; ++i)
        vis[i] = false;


        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int node = p.first;
            vis[node] = true;
            c[node] = p.second;
            ans = max(ans, p.second);
            for(auto val : adj[node]){

                if(c[val] && c[val] == p.second)
                return -1;

                if(!vis[val]){
                    q.push(make_pair(val, p.second+1));
                    c[val] = p.second+1;
                }
            }

            continue;
        }
        
        return ans;
    }
};
