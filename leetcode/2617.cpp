#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


static auto _______ = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:

    ll solve(vector<vector<int>> &g, int i, int j, vector<vector<ll>> &dp){
        int n = g.size();
        int m = g[0].size();

        // cout << i << " " << j << "\n";

        // if(i >= n || j >= m){
        //     cout << "eoob\n";
        //     return (ll)INT_MAX;
        // }

        if(dp[i][j] != -1) return dp[i][j]; 

        if(i == n-1 && j == m-1) return dp[i][j] = 1LL;
        if(g[i][j] == 0) return dp[i][j] = (ll)INT_MAX;

        ll moves = LLONG_MAX;
        int v = g[i][j];

        for(int ni = i+1; ni <= v+i; ++ni){
            if(ni >= n) break;
            moves = min(moves, 1LL + solve(g, ni, j, dp));
        }

        v = g[i][j];

        for(int nj = j+1; nj <= v+j; ++nj){
            if(nj >= m) break;
            moves = min(moves, 1LL + solve(g, i, nj, dp));
        }

        return dp[i][j] = moves;
    }

    int minimumVisitedCells(vector<vector<int>>& grid) {

        int n = grid.size(); int m = grid[0].size();
        vector<vector<ll>> dp(n+1, vector<ll> (m, -1));

        //cout << "s\n";

        ll res = solve(grid, 0, 0, dp);
        if(res >= (ll)INT_MAX) return -1;
        else return (int)res;
    }
};
