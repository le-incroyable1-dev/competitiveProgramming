#include <bits/stdc++.h>
#define mod 1000000007
typedef long long ll;

class Solution {
    
private:
    
    
public:
    int countWays(vector<vector<int>>& v) {
        
        int n = v.size();
        //int ans = 0;
        
        sort(v.begin(), v.end());
        
//         for(auto p : v){
//             cout << p[0] << " " << p[1] << "\n";
//         }
        
        
        int grps = 1;
        int e1 = INT_MIN;
        for(int i = 0; i < n-1; ++i){
            int e1 = max(e1, v[i][1]);
            int s2 = v[i+1][0];
            
            if(s2 > e1) grps++, e1 = INT_MIN;
            else continue;
        }
        
        //cout << grps << "\n";
        
        ll ans = 1;
        
        for(int i = 1; i <= grps; ++i){
            (ans *= 2)%=mod;
        }
        
        return ans;
        
    }
};
