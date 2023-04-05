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

    vector<int> *g;

    void cycle(int i, int &n, int &cycle_len){

        vector<int> len(n, INT_MAX);
        len[i] = 0;
        vector<int> par(n, -1);
        queue<int> q;
        q.push(i);

        while(!q.empty()){
            int sz = q.size();

            while(sz--){

                int cur = q.front(); q.pop();
                for(auto v : g[cur]){
                    if(len[v] == INT_MAX){
                        len[v] = len[cur] + 1;
                        q.push(v);
                        par[v] = cur;
                    }
                    else if(par[v] != cur && par[cur] != v){
                        cycle_len = min(cycle_len, len[v] + len[cur] + 1);
                    }
                }
            }

            continue;  
        } 

    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto p : edges) adj[p[0]].push_back(p[1]), adj[p[1]].push_back(p[0]);

        g = adj;

        int min_len = INT_MAX;
        for(int i = 0; i < n; ++i) cycle(i, n, min_len);

        return (min_len == INT_MAX ? -1 : min_len);

    }
};
