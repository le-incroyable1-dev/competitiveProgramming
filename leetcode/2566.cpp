#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int minMaxDifference(int num) {
        
        string s = to_string(num);
        
        string smax, smin;
        smax = s;
        smin = s;
        
        char rep1 = '!';
        char rep2 = '!';
        
        for(auto c : s){
            if(rep1 == '!' && c != '9') rep1 = c;
            if(rep2 == '!' && c != '0') rep2 = c;
        }
        
        for(auto &c : smax){
            if(c == rep1) c = '9';
        }
        
        for(auto &c : smin){
            if(c == rep2) c = '0';
        }
        
        ll max_val = stoll(smax);
        ll min_val = stoll(smin);
        
        
        
        ll ans = max_val - min_val;
        return (int)ans;
        
    }
};
