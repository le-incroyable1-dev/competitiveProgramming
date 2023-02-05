#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool possible(vector<int> &v, int n, int k, int val){
        
        for(int i = 0; i < n; ++i){
            if(v[i] <= val){
                k--;
                ++i;
            }
            
            if(k == 0) break;
        }
        
        return k==0;
        
    }
    
    int minCapability(vector<int>& v, int k) {
        
        int mine = *min_element(v.begin(), v.end());
        int maxe = *max_element(v.begin(), v.end());
        
        
        int n = v.size();
        
        int mid;
        
        int l = mine;
        int r = maxe;
        int ans = INT_MAX;
        
        while(l <= r){
            mid = r + (l-r)/2;
            
            if(possible(v, n, k, mid)){
                r = mid-1;
                ans = min(ans, mid);
            }
            else
                l = mid+1;
        }
        
        return ans;
    }
};
