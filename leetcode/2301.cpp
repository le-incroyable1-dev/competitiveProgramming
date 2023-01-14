#include <bits/stdc++.h>
using namespace std;


class Solution {
    
private:
    unordered_map<char, unordered_set<char>> cm;
    
    bool solve(int i, int j, int n, int m, string &s, string &sub){
        bool res = false;
        
        if(i >= n || j >= m)
            return false;
        
        char m1 = sub[j];
        
        //cout << i << " " << j << " " << m1 << " " << m2 << "\n";
        
        
        if(s[i] == m1 || cm[m1].find(s[i]) != cm[m1].end()){
            
            int index = 1;
            
            while(index < m){
                char c1 = sub[index];
                
                
                if(i+index >= n)
                    break;
                
                //cout << c1 << " " << c2 << "\n";
                
                if(s[i+index] == c1 || cm[c1].find(s[i+index]) != cm[c1].end()){
                    ++index;
                    continue;
                }
                else
                    break;
            }
            
            if(index == m)
                return true;
            
            res |= solve(i+1, j, n, m, s, sub);
            
        }
        else
            res |= solve(i+1, j, n, m, s, sub);
        
        
        return res;
    }
    
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        
        for(auto v : mappings)
            cm[v[0]].insert(v[1]);
        
        int n = s.length();
        int m = sub.length();
        
        bool ans = solve(0, 0, n, m, s, sub);
        return ans;
        
    }
};
