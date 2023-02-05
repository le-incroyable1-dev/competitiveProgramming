#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        unordered_set<int> s;
        
        for(auto val : banned)
            s.insert(val);
        
        int sum = 0;
        int count = 0;
        
        for(int i = 1; i <= n; ++i){
        
            if(s.find(i) == s.end()){
                
                if(sum + i <= maxSum){
                    sum += i;
                    count++;
                }
                else break;
                
            }
        }
        
        return count;
        
    }
};
