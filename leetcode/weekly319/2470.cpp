#include <bits/stdc++.h>
#define ll unsigned long long

class Solution {
public:
    
    ll gcd(ll a, ll b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    
    
    int subarrayLCM(vector<int>& arr, int k) {
        
        int n = arr.size();
        int ct = 0;
        ll ans;
        
        
        for(int i = 0; i < n; ++i){
            
            for(int j = i; j < n; ++j){
                
               if(j == i)
                   ans = arr[j];
                else{
                    ans = (ans)/(gcd((ll)arr[j], ans)) * (ll)arr[j];
                }
                
                if(ans == k)
                    ct++;
                
            }
        }
        
        return ct;
        
    }
};
