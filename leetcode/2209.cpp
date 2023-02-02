#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    
    int helper(string &floor, int k, int len, int index, int n, vector<int> &w, vector<vector<int>> &dp){
        
        if(dp[k][index] != -1) return dp[k][index];
        
        if(k == 0) return dp[k][index] = 0;
        if(index >= n) return dp[k][index] = 0;
        
        int next = min(index+len, n);
        
        int tiles_covered = w[min(n-1, index+len-1)] - w[index] + (floor[index] == '1');
        
        int res = 0;
        
        int put = helper(floor, k-1, len, next, n, w, dp) + tiles_covered;
        int dont_put = helper(floor, k, len, index+1, n, w, dp) + 0;
        
        res = max(put, dont_put);
        dp[k][index] = res;
        return res;
    }
    
    
    int minimumWhiteTiles(string floor, int k, int len) {
        
        int n = floor.length();
        vector<int> w;
        
        int ct = 0;
        
        for(auto c : floor){
            if(c == '1') ct++;
            w.push_back(ct);
        }
        
        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        
        
        //cout << ct << "\n";
        
        int cover = helper(floor, k, len, 0, n, w, dp);
        int ans = max(0, ct-cover);
        return ans;
        
    }
};
