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

    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {


        int n = coins.size();
        vector<set<int>> g(n);
        
        for(auto& e:edges)  g[e[0]].insert(e[1]),g[e[1]].insert(e[0]);
        queue<int> leaves;

        int totalEdges = edges.size()*2, deleted=0;

        for(int i = 0; i < n; ++i) if(g[i].size() == 1) leaves.push(i);
        //cout << "\n";

        while(!leaves.empty()){
            int i = leaves.front(); leaves.pop();

            if(g[i].size() == 0) continue;

            if(coins[i] == 0){
                int par = *g[i].begin();
                g[i].erase(par);
                g[par].erase(i);

                deleted += 2;

                if(g[par].size() == 1) leaves.push(par);
            }
            else{
                int par = *g[i].begin();
                g[i].erase(par);
                g[par].erase(i);

                deleted += 2;

                for(auto u : g[par]){
                    g[par].erase(u);
                    g[u].erase(par);

                    deleted += 2;

                    //if(g[u].size() == 1) leaves.push(u);
                }
            }
        }

        // for(auto s : g){
        //     for(auto u : s) cout << u << " ";
        //     cout << "\n";
        // }

        int ans = totalEdges - deleted;
        return ans;

    }
};
