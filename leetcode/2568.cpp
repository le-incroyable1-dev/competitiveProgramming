#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int minImpossibleOR(vector<int>& v) {
        
        for(int i = 0; i < 31; ++i){
            bool flag = false;
            
            for(int val : v){
                
                if(val == (1<<i)){
                    flag = true;
                    break;
                }
                
            }
            
            if(flag == false)
                return 1<<i;
        }
        
        return INT_MAX;
    }
};
