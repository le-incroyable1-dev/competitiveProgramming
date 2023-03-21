#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
    
        map<int, int> m;
        for(auto val : nums) m[(value + val%value)%value]++;
        for(int i = 0; i < value; ++i){
            if(m.find(i) == m.end()) m[i] = 0;
        }

        int val;
        int mincount = INT_MAX;

        for(auto &[v, count] : m){
            if(count < mincount) val = v, mincount = count;
            if(mincount == 0) return val;
        }

        int mex = val + mincount*value; 

        return mex;                                                  
        
    }
};
