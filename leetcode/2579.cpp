#include <bits/stdc++.h>
typedef long long ll;

class Solution {
public:
    long long coloredCells(int n) {
        
        if(n == 1) return 1;
        else if(n == 2) return 5;
        
        
        ll res = 13;
        ll diag = 3;
        
        for(ll cur = 4; cur <= n; ++cur){
            res += 4*diag;
            ++diag;
        }
        
        
        
        return res;
        
    }
};
