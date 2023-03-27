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

    
    int solve(vector<vector<int>> &g, vector<vector<vector<int>>> &dp, int r1, int c1, int c2){
        int n = g.size();

        // at any point r1 + c1 = r2 + c2
        // as the leg was reversed at a point
        // they remain on the same diagonal

        int r2 = r1 + c1 - c2;

        if(dp[r1][c1][c2] != INT_MIN) return dp[r1][c1][c2];
        if(r1 == n || r2 == n || c1 == n || c2 == n || g[r1][c1] == -1 || g[r2][c2] == -1) return dp[r1][c1][c2] = -69696969;

        
        if(r1 == n-1 && c1 == n-1) return dp[r1][c1][c2] = g[r1][c1];

        int res = 0;
        res += g[r1][c1] + (r1 == r2 ? 0 : g[r2][c2]);

        int p1down = max(solve(g, dp, r1+1, c1, c2), solve(g, dp, r1+1, c1, c2+1));  //p2 down or right
        int p1right = max(solve(g, dp, r1, c1+1, c2), solve(g, dp, r1, c1+1, c2+1)); //p2 down or right

        res += max(p1down, p1right);
        return dp[r1][c1][c2] = res;
    }

    int cherryPickup(vector<vector<int>>& g) {
        int ans = 0;
        int n = g.size(); int m = g[0].size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(n+1, INT_MIN)));

        ans = solve(g, dp, 0, 0, 0);
        ans = max(ans, 0);

        return ans;
    }
};
