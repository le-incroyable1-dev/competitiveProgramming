#include <bits/stdc++.h>
using namespace std;



bool isPossible(string &s, int i, int n, vector<int> &dp, unordered_set<string> &ss){

    if(dp[i] != -1) return dp[i];
    if(i == n) return dp[i] = 1;

    bool res = false;
    string cur = "";
    for(int j = i; j < n; ++j){
        cur += s[j];
        if(ss.find(cur) != ss.end()) res |= isPossible(s, j+1, n, dp, ss);
        
        if(res) break;
    }

    return dp[i] = res;
}

int Solution::wordBreak(string s, vector<string> &v) {
    
    unordered_set<string> ss;
    int n = s.length();
    for(auto str : v) ss.insert(str);
    vector<int> dp(n+1, -1);

    bool ans = isPossible(s, 0, n, dp, ss);
    return (int)ans;
}
