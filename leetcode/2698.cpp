#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int digits(int n)
    {
        string num = to_string(n);
        int d = num.size(); return d;
    }

    void partition(int num, int cur, bool &parts, int &target){
        
        if(parts) return;
        
        if(num == 0){
            if(cur == target) parts = true;
            return;
        }
        
        if(cur > target) return;
        
        
        string s = to_string(num);
        int add = 0;
        int n = s.length(); int i = 0;
        
        while(i < n && !parts){
            int pos = stoi(string(1, s[i]));
            add = add*10 + pos;
            
            int rem;
            if(i+1 < n) rem = stoi(s.substr(i+1));
            else rem = 0;
            
            partition(rem, cur+add, parts, target);
            ++i;
        }
        
        return;
    }
    
    int punishmentNumber(int n) {
        
        int res = 0;
        
        for(int i = 1; i <= n; ++i){
            bool parts = false;
            int num = i*i;
            
            partition(num, 0, parts, i);
            if(parts) res += num;
        }
        
        return res;
        
    }
};
