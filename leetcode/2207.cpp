#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        
        char c1 = pattern[0];
        char c2 = pattern[1];
        
        if(c1 == c2){
            ll i1 = 0;
            
            for(auto c : text){
                if(c == c1) i1++;
            }
            
            i1++;
            
            ll count = (i1)*(i1-1);
            count /= 2;
            return count;
            
        }
        
        ll i1 = 0;
        ll i2 = 0;
        
        
        
        ll count = 0;
        
        int n = text.length();
        
        for(int i = n-1; i >= 0; i--){
            if(text[i] == c2) i2++;
            else if(text[i] == c1){
                i1++;
                count += i2;
            }
        }
        
        ll add = max(i2, i1);
        count += add;
        
        return count;
        
    }
};
