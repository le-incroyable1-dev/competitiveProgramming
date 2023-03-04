#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitNum(int num) {
        
        string s = to_string(num);
        int n = s.length();
        
        sort(s.begin(), s.end());
        
        string s1, s2;
        
        for(int i = 0; i < n; ++i){
            if(i%2 == 0) s1 += s[i];
            else s2 += s[i];
        }
        
        int num1 = stoi(s1);
        int num2 = stoi(s2);
        
        int ans = num1 + num2;
        return ans;
    }
};
