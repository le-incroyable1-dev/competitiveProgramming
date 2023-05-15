#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    vector<vector<int>> dp;
    vector<vector<bool>> vis;
    
    int solve(int i, int j, vector<vector<int>>& g){
        int n = g.size();
        int m = g[0].size();

        if(dp[i][j] != -1) return dp[i][j];

        vis[i][j] = true;
        int res = 0;

        int m1 = 0;
        int m2 = 0;
        int m3 = 0;

        if(i-1 >= 0 && j+1 < m && !vis[i-1][j+1] && g[i-1][j+1] > g[i][j]) m1 = 1 + solve(i-1, j+1, g);
        if(j+1 < m && !vis[i][j+1] && g[i][j+1] > g[i][j]) m2 = 1 + solve(i, j+1, g);
        if(i+1 < n && j+1 < m && !vis[i+1][j+1] && g[i+1][j+1] > g[i][j]) m3 = 1 + solve(i+1, j+1, g);

        res = max(res, max(m1, max(m2, m3)));
        //ans = max(ans, res);

        return dp[i][j] = res;
    }

    int maxMoves(vector<vector<int>>& grid) {
        
        //cout << flush;
        int n = grid.size();
        int m = grid[0].size();
        vis.resize(n, vector<bool>(m, false));
        dp.resize(n, vector<int>(m, -1));

        int ans = 0;
        for(int i = 0; i < n; ++i){
           if(!vis[i][0]) ans = max(ans, solve(i, 0, grid));
        }
        return ans;
    }
};
