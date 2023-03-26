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

    int ans = -1;

    void find(vector<int> &e, unordered_map<int, int> &len, int v, int l, vector<bool> &vis, bool &found){

        if(v == -1) return;

        if(e[v] == -1) return;
        if(vis[e[v]] && len.find(e[v]) != len.end()){
            ans = max(ans, len[v] + 1 - len[e[v]]);
        }
        else if(!vis[e[v]]){
            len[e[v]] = len[v] + 1;
            vis[e[v]] = true;
            find(e, len, e[v], l+1, vis, found);
        }

        return;

    }

    int longestCycle(vector<int>& e) {
        int n = e.size();

        vector<bool> vis(n, false);
        
        for(int i = 0; i < n; ++i){

            if(vis[i]) continue;

            unordered_map<int, int> len;
            bool found = false;
            find(e, len, i, 0, vis, found);
           
        }

        return ans;
    }
};
