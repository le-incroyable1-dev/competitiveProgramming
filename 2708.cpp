#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return (ll)nums[0];
        
        ll res = 1LL;
        int mx = -10;
        
        vector<int> neg;
        for(auto val : nums){
            mx = max(mx, val);
            if(val < 0) neg.push_back(val);
            else if(val > 0) res *= 1LL*val;
        }
        
        // cout << res << "\n";
        // for(auto val : neg) cout << val;
        // cout << "\n";
        
        int m = neg.size();
        
        if(mx == 0){
            if(m == 0) return 0LL;
            else{
                if(m%2 == 0){
                    for(auto val : neg) res *= 1LL * val;
                    return res;
                }
                else{
                    
                    if(m == 1) return 0LL;
                    sort(neg.begin(), neg.end());
                    for(int i = 0; i < neg.size()-1; ++i) res *= 1LL * neg[i];
                    return res;
                }
            }
        }
        else{
            
            if(mx > 0){
                if(m%2 == 0){
                    for(auto val : neg) res *= 1LL * val;
                    return res;
                }
                else{
                    sort(neg.begin(), neg.end());
                    for(int i = 0; i < neg.size()-1; ++i) res *= 1LL * neg[i];
                    return res;
                }
            }
            else{
                if(m%2 == 0){
                    for(auto val : neg) res *= 1LL * val;
                    return res;
                }
                else{
                    sort(neg.begin(), neg.end());
                    for(int i = 0; i < neg.size()-1; ++i) res *= 1LL * neg[i];
                    return res;
                }
                
            }
            
        }
        
        
        return -1LL;
    }
};
