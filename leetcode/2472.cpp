#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    

    int maxPalindromes(string s, int k) {

        vector<vector<bool>> pal(2002, vector<bool>(2002, false));

        int n = s.length();

        if(k == 1)
        return n;
        else if(k == n){
            string rs = s;
            reverse(rs.begin(), rs.end());
            return (int)(rs == s);
        }

        for (int len = 1; len <= k + 1; ++len)
        for (int i = 0, j = i + len - 1; j < s.size(); ++i, ++j)
            pal[i][j] = (len < 3 ? true : pal[i + 1][j - 1]) && (s[i] == s[j]);


        int ans = 0;
        
        vector<int> dp(n, 0);

        for(int i = k-1; i < n; ++i){
            dp[i] = dp[i-1];

            for(int j = i-1; j >= 0; j--){

                if(pal[j][i] && (i-j+1 >= k)){
                    if(j == 0){
                        dp[i] = max(dp[i], 1);
                    }
                    else{
                        dp[i] = max(dp[i], 1 + dp[j-1]);
                    }

                    
                }
            }

            ans = max(ans, dp[i]);
        }

        for(auto val : dp)
        cout << val << "\n";

        return ans;
        
    }
};
