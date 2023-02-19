#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    unordered_map<int, int> m;
    
    int minOperations(int n) {
        
        int ans = 1;
        
        if(m.find(n) != m.end()) return m[n];
        
        //cout <<n << "\n";
        
        if(n == 0) return m[n] = 0;
        
        
        if(floor(log2(n)) == ceil(log2(n))) return m[n] = ans;
        
        int ch1, ch2;
        
        ch1 = minOperations(n-pow(2,floor(log2(n))));
        ch2 = minOperations(pow(2, ceil(log2(n)))-n);
        
        
        ans += min(ch1, ch2);
        m[n] = ans;
        return ans;
        
    }
};
