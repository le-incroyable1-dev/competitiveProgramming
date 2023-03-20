#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int solve(vector<int> &v, int &k, int mask, int i){
        if(i == v.size()) return (mask > 0);
        int res = 0;
        res += solve(v, k, mask, i+1);
        
        bool add = true;
        for(int j = 0; j < 20; ++j){
            if((1 << j) & mask){
                if(abs(v[i]-v[j]) == k){
                    add = false;
                    break;
                }
            }
        }
        
        if(add) mask |= (1 << i), res += solve(v, k, mask, i+1);
        return res;
    }
    
    
    int beautifulSubsets(vector<int>& v, int k) {
        int n = v.size();
        int mask = 0;
        
        int ans = solve(v, k, 0, 0);
        
        return ans;
        
    }
};
