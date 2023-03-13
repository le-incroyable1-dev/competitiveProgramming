#include <bits/stdc++.h>
using namespace std;

int Solution::solve(vector<vector<int> > &v) {
    
    int n = v.size();
    sort(v.begin(), v.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(v[0][1]);
    
    for(int i = 1; i < n; ++i){
        vector<int> meet = v[i];
        
        int low = pq.top();
        
        if(low <= meet[0]){
            pq.pop(); pq.push(meet[1]);
        }
        else pq.push(meet[1]);
    }
    
    int ans = pq.size();
    return ans;
}
