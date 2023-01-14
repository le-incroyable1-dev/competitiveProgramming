#include <bits/stdc++.h>
typedef unsigned long long ll;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        vector<ll> pre;
        ll sum = 0;
        for(auto val : nums){
            sum += val;
            pre.push_back(sum);
        }
        
        ll n = nums.size();
        
        ll cur_score;
        ll count = 0;
        ll i = 0;
        ll j = 0;
        
        while(i < n && j < n){
            
            if(i > j)
                break;
            
            cur_score = (pre[j]-pre[i]+(ll)nums[i])*(j-i+1);
            
            if(cur_score < k){
                count += j-i+1;
                ++j;
            }
            else{
                if(i == j){
                    ++i;
                    ++j;
                }
                else if(i > j) break;
                else ++i;
            }
        }
        
        return count;
    }
};
