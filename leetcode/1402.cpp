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

private:
    

public:


    int solve(vector<int> &s, int i, int t, vector<vector<int>> &dp){

        if(dp[i][t] != INT_MIN) return dp[i][t];
        if(i == s.size()) return dp[i][t] = 0;

        int res = 0;
        int skip = solve(s, i+1, t, dp);
        int make = solve(s, i+1, t+1, dp) + s[i]*t;

        res = max(res, skip);
        res = max(res, make);

        return dp[i][t] = res;

    }

    int maxSatisfaction(vector<int>& s) {
        int n = s.size();
        sort(s.begin(), s.end());
        vector<vector<int>> dp(505, vector<int>(505, INT_MIN));

        int chef_ko_satisfy = solve(s, 0, 1, dp);
        return chef_ko_satisfy;
    }
};
