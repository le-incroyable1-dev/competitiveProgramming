#include<bits/stdc++.h>
using namespace std;

int Solution::isMatch(const string A, const string B) {
    
    int n = A.length();
    int m = B.length();
    
    if(A == B)
    return 1;
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    dp[0][0] = 1;
    
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= m; ++j){
            if(!i && !j) continue;
            
            if(j && B[j-1] == '*'){
                if(j) dp[i][j] |= dp[i][j-1];
                if(i) dp[i][j] |= dp[i-1][j];
                if(i && j) dp[i][j] |= dp[i-1][j-1];
            }
            else if(j && B[j-1] == '?'){
                if(i && j) dp[i][j] |= dp[i-1][j-1];
            }
            else{
                if(i && j){
                    dp[i][j] = (A[i-1] == B[j-1]) && dp[i-1][j-1];
                }
            }
        }
    }
    
    return dp[n][m];
    
}
