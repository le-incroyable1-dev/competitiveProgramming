#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isPrime(int n)
    {
        // Corner cases
        if (n <= 1)
            return false;
      
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    
    
    int diagonalPrime(vector<vector<int>>& v) {
        
        int n = v.size();
        int ans = 0;
        for(int i = 0; i < n; ++i){
            int val = v[i][i];
            if(isPrime(val)) ans = max(ans, val);
            val = v[i][n-1-i];
            if(isPrime(val)) ans = max(ans, val);
        }
        
        return ans;
        
    }
};
