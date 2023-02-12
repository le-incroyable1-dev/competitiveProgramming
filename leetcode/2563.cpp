#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
    
private:
    
    int upper_binary(vector<int> &v, int up, int n){
        
        int l = 0;
        int r = n-1;
        int res = 0;
        
        while(l <= r){
            int mid = l + (r-l)/2;
            
            if(v[mid] <= up){
                l = mid+1;
                res = max(res, mid);
            }
            else{
                r = mid-1;
            }
            
            
        }
        
        return res;
        
    }
    
    
public:
    long long countFairPairs(vector<int>& v, int l, int u) {
        
        ll ans = 0;
        sort(v.begin(), v.end());
        int n = v.size();
        
        for(int i = 0; i < n; ++i){
            
            int a = v[i];
            
            int low = l-a;
            int up = u-a;
            
            int li = 0;
            int ui = 0;
            
            li = lower_bound(v.begin(), v.end(), low) - v.begin();
            ui = upper_binary(v, up, n);
        
            
            if(ui == n) ui--;
            if(v[ui] > up) ui--;
            
            if(li <= i) li = i+1;
            
            //cout << i << " " << a <<" " << li << " " << ui << "\n";
            
            ll cur = 0;
            
            if(ui < n && li < n && ui > i && li > i){
                cur = max(0LL, ((ll)ui-(ll)li+1LL));
                ans += cur;
            }
            
        }
        
        cout << "\n";
        
        return ans;
        
        
    }
};
