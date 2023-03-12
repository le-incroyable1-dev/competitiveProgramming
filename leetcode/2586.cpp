#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
    
    int vowelStrings(vector<string>& w, int l, int r) {
        
        int ans = 0;
        for(int i = l; i <= r; ++i){
            string s = w[i];
            
            int n = s.length();
            
            if(isVowel(s[0]) && isVowel(s[n-1])) ++ans;
        }
        
        return ans;
    }
};
