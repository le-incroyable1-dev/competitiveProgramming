#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

class Solution {
public:
    vector<int> divisibilityArray(string w, int m) {
        
        vector<int> ans;
        
        
        int n = w.length();
        
        string num;
        num = w[0];
        
        ll rem = stoll(num)%m;
        
        if(rem == 0) ans.pb(1);
        else ans.pb(0);
        
        
        for(int i = 1; i < n; ++i){
            string num = "";
            num += w[i];
            
            ll new_rem = (rem*10)%m + (stoll(num)%m);
            new_rem %= m;
        
            
            if(new_rem == 0) ans.pb(1);
            else ans.pb(0);
            
            rem = new_rem;
            
        }
        
        return ans;
        
        
    }
};
