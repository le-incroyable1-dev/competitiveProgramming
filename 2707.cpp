#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    unordered_set<string> store;
    vector<int> dp;
    
    int solve(int i, string &s){
        
        int n = s.length();
        
        if(dp[i] != -1) return dp[i];
        if(i == n) return dp[i] = 0;
        
        string cur = "";
        int res = n;
        
        for(int j = i; j < n; ++j){
            cur += s[j];
            if(store.find(cur) != store.end()){
                res = min(res, 0 + solve(j+1, s));
            }
            else{
                res = min(res, j-i+1 + solve(j+1, s));
            }
        }
        
        return dp[i] = res;
        
    }
    
    int minExtraChar(string s, vector<string>& d) {
        
        cout << flush;
        for(auto s : d) store.insert(s);
        int n = s.length();
        dp.resize(n+2, -1);
        
        int ans = n;
        
        ans = min(ans, solve(0, s));
        dp.clear();
        return ans;
    }
};
