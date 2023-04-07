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

    void dfs(vector<vector<int>> &g, int i, int j){
        int n = g.size();
        int m = g[0].size();

        if(i >= n || j >= m || i < 0 || j < 0 || g[i][j] == 0) return;   
        
        g[i][j] = 0;
        dfs(g,i,j+1);
        dfs(g,i,j-1);
        dfs(g,i+1,j);
        dfs(g,i-1,j);

        return;
    }

    int numEnclaves(vector<vector<int>>& g) {

        int n = g.size();
        int m = g[0].size();

        for(int i = 0; i < n; ++i){
            dfs(g, i, 0);
            dfs(g, i, m-1);
        }

        for(int j = 0; j < m; ++j){
            dfs(g, 0, j);
            dfs(g, n-1, j);
        }

        int ans = 0;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(g[i][j] == 1) ++ans;
            }
        }

        return ans;
    }
};
