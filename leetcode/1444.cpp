#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;


class Solution {

private:

    void prefixSum2D(vector<string> &a, vector<vector<int>> &psa, vector<vector<vector<int>>> &dp)
    {

        int n = psa.size();
        int m = psa[0].size();

        psa[n-1][m-1] = (a[n-1][m-1] == 'A');

        for(int i = n-2; i >= 0; i--) psa[i][m-1] = psa[i+1][m-1] + (a[i][m-1] == 'A');
        for(int i = m-2; i >= 0; i--) psa[n-1][i] = psa[n-1][i+1] + (a[n-1][i] == 'A');

        for(int i = n-2; i >= 0; i--){
            for(int j = m-2; j >= 0; j--){
                psa[i][j] = psa[i][j+1] + psa[i+1][j] - psa[i+1][j+1] + (a[i][j] == 'A');
            }
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j) dp[0][i][j] = (psa[i][j] > 0);
        }

        return;
    }


public:
  
    int ways(vector<string>& p, int k) {

        int n = p.size();
        int m = p[0].size();

        vector dp(k, vector(n, vector<int>(m)));
        vector<vector<int>> apples(n, vector<int>(m, 0));
        prefixSum2D(p, apples, dp);
        

        for(int cuts = 1; cuts < k; ++cuts){
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){

                    for(int ni = i+1; ni < n; ++ni){
                        if(apples[i][j] - apples[ni][j] > 0)
                        (dp[cuts][i][j] += dp[cuts-1][ni][j])%=mod;
                    }

                    for(int nj = j+1; nj < m; ++nj){
                        if(apples[i][j] - apples[i][nj] > 0)
                        (dp[cuts][i][j] += dp[cuts-1][i][nj])%=mod;
                    }

                    continue;

                }
            }
        }
        

        int res = dp[k-1][0][0];
        return res;
    }
};
