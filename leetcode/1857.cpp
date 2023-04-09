#include <bits/stdc++.h>
using namespace std;

static auto _______ = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:

    int ans = 0;

    // vector<bool> visited;
    // void dfs(int v, vector<int> &ans) {
    //     visited[v] = true;
    //     for (int u : adj[v]) {
    //         if (!visited[u])
    //             dfs(u);
    //     }
    //     ans.push_back(v);
    // }

    // void topo_sort(vector<int> &ans, int n) {
    //     visited.assign(n, false);
    //     ans.clear();
    //     for (int i = 0; i < n; ++i) {
    //         if (!visited[i])
    //             dfs(i);
    //     }
    //     reverse(ans.begin(), ans.end());
    // }

    bool cycle (int node, 
            bool *visited, bool *inStack, vector<int> *adj){
        // Check if node exists in the
        // recursive stack.
        if (inStack[node])
            return true;
        
        // Check if node is already visited.
        if (visited[node])
            return false;
        
        // Marking node as visited.
        visited[node] = true;

        // Marking node to be present in
        // recursive stack.
        inStack[node] = true;

        // Iterate for all adjacent of 
        // 'node'.
        for (int v : adj[node]){
            // Recurse for 'v'.
            if (cycle(v, visited, inStack, adj))
                return true;
        }

        // Mark 'node' to be removed
        // from the recursive stack.
        inStack[node] = false;

        // Return false if no cycle exists.
        return false;
    }


    int fill(vector<vector<int>> &dp, int v, vector<int> *g, int c, string &colors){
        int res = ((colors[v]-'a') == c);

        if(dp[v][c] != -1) return dp[v][c];
        
        for(auto u : g[v]){
            int cur = fill(dp, u, g, c, colors) + ((colors[v] - 'a') == c);
            res = max(res, cur);
        }

        ans = max(ans, res);
        return dp[v][c] = res;
    }

    void solve(int v, vector<int> *g, vector<vector<int>> &dp, string &colors){
        for(int c = 0; c < 26; ++c){
            int cur = fill(dp, v, g, c, colors);
            ans = max(ans, cur);
        }
    }

    

    int largestPathValue(string colors, vector<vector<int>>& e) {

        int n = colors.size();
        vector<int> g[n];
        for(auto v : e) g[v[0]].push_back(v[1]);

        vector<vector<int>> dp(n, vector<int>(26, -1));

        bool vis[n];
        bool is[n];

        for(int i = 0; i < n; ++i) vis[i] = false, is[i] = false;

        for(int i = 0; i < n; ++i){
            if(vis[i]) continue;
            if(cycle(i, vis, is, g)) return -1;
        }

        // vector<int> topo;
        // topo_sort(topo, n);

        for(int i = 0; i < n; ++i) solve(i, g, dp, colors);

        return ans;
        
    }
};
