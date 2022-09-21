#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int i = 0;
        int j = 0;
        
        int max_len = 1;
        int res = 0;
        
        for(int i = 0; i < n; i++){
            while((res & nums[i]) != 0)
                res ^= nums[j++];
            
            res |= nums[i];
            max_len = max(max_len, i-j+1);
        }
        
        return max_len;
        
    }
};
