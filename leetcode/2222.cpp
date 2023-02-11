#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    long long numberOfWays(string s) {
        
        int n = s.length();
        
        int oc = 0;
        int zc = 0;
        
        vector<int> ones(n, 0);
        vector<int> zeroes(n, 0);
        
        for(int i = 0; i < n; ++i){
            if(s[i] == '0') ++zc;
            else ++oc;
            
            ones[i] = oc;
            zeroes[i] = zc;
        }
        
        ll ans = 0;
        
        for(int i = 0; i < n; ++i){
            if(s[i] == '0'){
                ans += (ll)(ones[i])*(ll)(oc-ones[i]);
            }
            else{
                ans += (ll)(zeroes[i])*(ll)(zc - zeroes[i]);
            }
        }
        
        return ans;
        
    }
};
