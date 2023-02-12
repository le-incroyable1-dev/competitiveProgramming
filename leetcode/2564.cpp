#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

class Solution {
public:
    vector<vector<int>> substringXorQueries(string str, vector<vector<int>>& queries) {
        
        vector<vector<int>> ans;
        int n = str.length();
        
        for(auto q : queries){
            
            int l = INT_MAX;
            int r = INT_MAX;
            int len = INT_MAX;
            
            ll target = q[0]^q[1];
            //cout << target << "\n";
            
            ll cur = 0;
            
            for(int s = 0; s < n; ++s){
                
                cur = 0;
                
                for(int i = s; i < n; ++i){
                    cur = (cur*2) + (str[i] == '1');
                    
                    if(cur == target){
                        if(len > (i-s+1)){
                            l = s;
                            r = i;
                            len = i-s+1;
                        }
                    }
                    
                }
            }
            
            if(len == INT_MAX){
                l = -1;
                r = -1;
            }
            
            ans.push_back({l, r});
            
        }
        
        //cout << "\n";
        return ans;
        
    }
};
