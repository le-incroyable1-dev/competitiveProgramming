#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        
        vector<int> ans;
        vector<int> v(n, 0);
        int res = 0;
        
        for(auto q : queries){
            int pos = q[0]; int col = q[1];
            int prev_col = v[pos];
            
            
            if(prev_col == col) { ans.push_back(res); continue; }
            
            if(pos > 0){
                if(v[pos-1] == prev_col && v[pos-1] != 0) res--;
                else if(v[pos-1] == col) ++res;
            }
            
            if(pos < n-1){
                if(v[pos+1] == prev_col && prev_col != 0) res--;
                else if(v[pos+1] == col) ++res;
            }
            
            v[pos] = col;
            ans.push_back(res);
            continue;
        }
        
        return ans;
    }
};
