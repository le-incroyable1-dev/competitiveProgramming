#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<vector<int> > &A) {
    
    vector<int> merged;
    
    int n = A[0].size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 0 ; i < A.size(); ++i){
        pq.push(make_pair(A[i][0], n*i + 0));
    }
    
    
    
    while(!pq.empty()){
        pair<int, int> p = pq.top(); pq.pop();
        merged.push_back(p.first);
        int x = p.second;
        int i = x/n;
        int j = x%n;
        
        if(j+1 < n) pq.push(make_pair(A[i][j+1], n*i + j + 1));
    }
    
    return merged;
}
