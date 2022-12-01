#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int ans = INT_MIN;

    void dfs_alice(vector<vector<bool>> &adj, int cur, vector<bool> &vis, vector<int> &bob_dist, unordered_set<int> &path, int n, int dist, int res, vector<int> &amount){

        
        vis[cur] = true;
        bool leaf = true;

        if(path.find(cur) != path.end()){
            if(dist < bob_dist[cur])
            res += amount[cur];
            else if(dist == bob_dist[cur])
            res += amount[cur]/2;
        }
        else
        res += amount[cur];

        for(int i = 0; i < n; ++i){
            if(adj[cur][i]){
                if(!vis[i]){
                    leaf = false;
                    dfs_alice(adj, i, vis, bob_dist, path, n, dist+1, res, amount);
                }
            }
        }

        if(leaf){
            ans = max(ans, res);
            cout << cur << " " << ans << "\n";
        }
        return;

    }

    void dfs_bob(vector<vector<bool>> &adj, int cur, vector<bool> &vis, vector<int> &bob_dist, vector<int> &bob_par, int n, int par, int dist){

        bob_dist[cur] = dist;
        bob_par[cur] = par;
        vis[cur] = true;

        if(cur == 0)
        return;

        for(int i = 0; i < n; ++i){
            if(adj[cur][i] && !vis[i])
            dfs_bob(adj, i, vis, bob_dist, bob_par, n, cur, dist+1);
        }

        return;

    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {

        int n = edges.size() + 1;
        vector<vector<bool>> adj(n, vector<bool>(n, false));

        for(int i = 0; i < n-1; ++i){
            adj[edges[i][0]][edges[i][1]] = true;
            adj[edges[i][1]][edges[i][0]] = true;;
        }
        
        vector<int> bob_dist(n, -1);
        vector<int> bob_par(n, -1);

        bob_dist[bob] = 0;
        bob_par[bob] = bob;
        vector<bool> vis(n, false);

        cout << "dfs_bob" << "\n";
        dfs_bob(adj, bob, vis, bob_dist, bob_par, n, bob, 0);

        int trace_back = 0;
        unordered_set<int> bob_path;

        while(1){
            bob_path.insert(trace_back);

            if(trace_back == bob)
            break;
            
            trace_back = bob_par[trace_back];
        }

        for(int i = 0 ;i < n; ++i)
        vis[i] = false;

        for(auto val : bob_path)
        cout << val << " ";

        cout << "\n" << "dfs_alice" << "\n";
        dfs_alice(adj, 0, vis, bob_dist, bob_path, n, 0, 0, amount);

        return ans;

    }
};
