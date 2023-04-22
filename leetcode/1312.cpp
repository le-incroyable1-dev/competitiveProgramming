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

    vector<vector<int>> dp;
    int insert(int i, int j, string &s){

        if(dp[i][j] != -1) return dp[i][j];
        if(j == i) return dp[i][j] = 0;
        else if(j-i == 1){
            if(s[i] == s[j]) return dp[i][j] = 0;
            else return dp[i][j] = 1;
        }

        int ops = INT_MAX;
        int c1 = INT_MAX;
        if(s[i] == s[j]) c1 = insert(i+1, j-1, s);
        int c2 = 1 + insert(i, j-1, s);
        int c3 = 1 + insert(i+1, j, s);

        ops = min(ops, c1);
        ops = min(ops, c2);
        ops = min(ops, c3);

        return dp[i][j] = ops;
    }

    int minInsertions(string s) {
        int n = s.length();
        dp.resize(n+1, vector<int>(n+1, -1));
        int ans = insert(0, n-1, s);
        return ans;
    }
};
