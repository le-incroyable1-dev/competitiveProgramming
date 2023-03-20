#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    
    bool timePossible(ll time, vector<int> &ranks, ll cars){
        
        for(auto val : ranks){
            ll cur = sqrt((time/(ll)val));
            cars -= cur;
            
            if(cars <= 0LL) break;
        }
        
        return (cars <= 0LL);
    }
    
    
    long long repairCars(vector<int>& ranks, int cars) {
        ll ans = LLONG_MAX;
        
        ll l = 0;
        ll r = LLONG_MAX;
        
        while(l <= r){
            //cout << l << " " << r << "\n";
            ll cur_time = l + (r-l)/2;
            
            if(timePossible(cur_time, ranks, (ll)cars))
                r = cur_time - 1, ans = min(ans, cur_time);
            else
                l = cur_time + 1;
        }
        
        return ans;
        
        
    }
};
