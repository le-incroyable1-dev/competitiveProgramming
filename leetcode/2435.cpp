#include <bits/stdc++.h>
using namespace std;
#define md 1000000007


class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, 0)));
        dp[0][0][grid[0][0]%k] = 1;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                for(int mod = 0; mod <= k; ++mod){
                    int nmod = (mod + grid[i][j])%k;

                    if(i-1 >= 0)
                    dp[i][j][nmod] += (dp[i-1][j][mod]%md);

                    if(j-1 >= 0)
                    dp[i][j][nmod] += (dp[i][j-1][mod]%md);

                    dp[i][j][nmod] %= md;
                }
            }
        }

        return dp[n-1][m-1][0];
    }
};
