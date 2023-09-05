#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;


class Solution {

private:

    vector<bool> vis;
    int L;
    int N;
    int timer = 0;
    vector<int> tin;
    vector<int> tout;
    vector<vector<int>> up;
    vector<vector<int>> freq;

public:

    //using binary lifting to get lowest common ancestor
    void dfs_lca(int i, int p, vector<vector<pii>> &g){
        
        tin[i] = ++timer;
        
        //set parent
        up[i][0] = p;

        for(int j = 1; j <= L; ++j){
            up[i][j] = up[up[i][j-1]][j-1];
        }

        for(auto [u, w] : g[i]){
            if(u == p) continue;
            dfs_lca(u, i, g);
        }

        tout[i] = ++timer;
        return;
    }

    bool is_ancestor(int i, int j){
        return tin[i] <= tin[j] && tout[i] >= tout[j];    
    }

    int get_lca(int i, int j){
        if(is_ancestor(i, j)) return i;
        else if(is_ancestor(j, i)) return j;  


        for(int a = L; a >= 0; a--){
            if(!is_ancestor(up[i][a], j)) i = up[i][a];
        }

        int lca = up[i][0];
        return lca;  
    }

    void preprocess_lca(int &n, vector<vector<pii>> &g){
        N = n;
        L = ceil(log(n));
        timer = 0;
        tin.resize(n, 0);
        tout.resize(n, 0);
        up.assign(n, vector<int>(L+1));
        
        //parent of root = root = 0
        dfs_lca(0, 0, g);
    }

    void dfs_set_freq(vector<int> v, vector<vector<pii>> &g, int i){
        vis[i] = true;
        freq[i] = v;

        for(auto [u, w] : g[i]){
            if(vis[u]) continue;
            v[w]++;
            dfs_set_freq(v, g, u);
            v[w]--;
        }

        return;
    }

    void set_freq(vector<vector<pii>> &g, int &n){
        freq.resize(n, vector<int>(26+1, 0));
        vector<int> v(26+1, 0);
        vis.resize(n, false);

        dfs_set_freq(v, g, 0);
        return;
    }

    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        
        vector<int> ops;

        vector<vector<pii>> g(n);
        for(auto e : edges) {
            g[e[0]].emplace_back(e[1], e[2]);
            g[e[1]].emplace_back(e[0], e[2]);
        }

        //set root to node 0, say
        vis.resize(n, false);
        preprocess_lca(n, g);
        set_freq(g, n);

        // for(auto v : freq){
        //     for(auto u : v) cout << u << " ";
        //     cout << "\n";
        // }

        for(auto q : queries){
            int s = q[0]; int e = q[1];
            int lca = get_lca(s, e);

            vector<int> root_to_s = freq[s];
            vector<int> root_to_e = freq[e];
            vector<int> root_to_lca = freq[lca];

            vector<int> res(26+1, 0);
            for(int i = 0; i <= 26; ++i) res[i] = root_to_e[i] + root_to_s[i] - 2*root_to_lca[i];

            int total_wts_count = 0;
            int max_freq = -1;

            for(auto u : res){ max_freq = max(max_freq, u); total_wts_count += u; }
            int cur_ops = total_wts_count - max_freq;
            ops.push_back(cur_ops);
        }

        return ops;

    }
};
