#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int miceAndCheese(vector<int>&r1, vector<int>& r2, int k) {
        
        int ans = 0;
        int n = r1.size();
        
        priority_queue<int>pq;
        
        for(int i=0 ; i < n; ++i){
           
           pq.push(r1[i]-r2[i]);
           ans+=r2[i];
        
        }
        
        
        while(k > 0){
            ans += pq.top(); pq.pop();
            k--;
        }
        
        
        return ans;
    }
};
