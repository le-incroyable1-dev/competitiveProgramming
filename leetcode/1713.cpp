// O(nlgn) //////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;


class Solution {

private:

    int lis_OP(vector<int> &a){

        vector<int> dp;

        for(auto val : a){

            int pos = lower_bound(dp.begin(), dp.end(), val) - dp.begin();

            if(pos == dp.size()) dp.push_back(val);
            else dp[pos] = val;
        }

        return dp.size();
    }

public:
    int minOperations(vector<int>& t, vector<int>& a) {
        
        int n = t.size();
        int m = a.size();

        unordered_map<int, int> mp;
        for(int i = 0; i <n; ++i) mp[t[i]] = i;

        vector<int> an;

        //for(auto p : mp) cout << p.first << " " << p.second << "\n";

        for(int i = 0; i < m; ++i){

            //cout << a[i] << " ";
            if(mp.find(a[i]) != mp.end()){
                an.push_back(mp[a[i]]);
                //cout << mp[a[i]];
            }

            //cout << "\n";
        }

        mp.clear();
        int common = lis_OP(an);
        int ans = n-common;

        return ans;
    }
};

/////////////////////////////////////////////////////////////////////

// O(n^2) ///////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    int lcs(vector<int> &X, vector<int> &Y, int m, int n,
            vector<vector<int> >& dp)
    {
        if (m == 0 || n == 0)
            return 0;
        if (X[m - 1] == Y[n - 1])
            return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);
    
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        return dp[m][n] = max(lcs(X, Y, m, n - 1, dp),
                            lcs(X, Y, m - 1, n, dp));
    }


public:
    int minOperations(vector<int>& target, vector<int>& arr) {

        int m = target.size();
        int n = arr.size();

        //cout << s1 << " " << s2 << "\n";

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        int common = lcs(target, arr, m, n, dp);

        //cout << common << "\n";
        int ans = m - common;
        return ans;
    }
};

///////////////////////////////////////////
