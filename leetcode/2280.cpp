#include <bits/stdc++.h>
using namespace std;
typedef long double d;

class Solution {
public:
    int minimumLines(vector<vector<int>>& sp) {
        
        sort(sp.begin(), sp.end());
        int n = sp.size();
        
        if(n == 1) return 0;
        else if(n == 2) return 1;
        
        d cur_slope;
        if(sp[1][0] == sp[0][0])
        cur_slope = (d)INT_MAX;
        else
        cur_slope = ((d)sp[1][1] - (d)sp[0][1])/((d)sp[1][0] - (d)sp[0][0]);
        
        //cout << cur_slope << "\n";
        int ans = 1;
        
        for(int i = 1; i <= n-2; ++i){
            
            d new_slope;
            if(sp[i+1][0] == sp[i][0])
            new_slope = (d)INT_MAX;
            else
            new_slope = ((d)sp[i+1][1] - (d)sp[i][1])/((d)sp[i+1][0] - (d)sp[i][0]);
            
            //cout << new_slope << "\n";
            
            if(new_slope != cur_slope){
                ++ans;
                cur_slope = new_slope;
            }
            
        
        }
        
        return ans;
        
    }
};
