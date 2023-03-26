#include <bits/stdc++.h>
using namespace std;

vector<int> Solution::solve(vector<int> &a, vector<int> &b) {
    
    int n  = a.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
        
    vector<int> ans;
    int an = a[n-1];
    int bn = b[n-1];
    
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(make_pair(an+bn, make_pair(n-1, n-1)));
    
    set<pair<int, int>> s;
    s.insert(make_pair(n-1, n-1));
    
    int k = n;
    while(k--){
        pair<int, pair<int, int>> p = pq.top(); pq.pop();
        int sum = p.first;
        pair<int, int> ip = p.second;
    
        
        ans.push_back(sum);
        int l = ip.first; int r = ip.second;
        
        if(r-1 >= 0 && l >= 0 && s.find(make_pair(l, r-1)) == s.end()) pq.push(make_pair(a[l] + b[r-1], make_pair(l, r-1))), s.insert(make_pair(l, r-1));
        if(l-1 >= 0 && r >= 0 && s.find(make_pair(l-1, r)) == s.end()) pq.push(make_pair(a[l-1] + b[r], make_pair(l-1, r))), s.insert(make_pair(l-1, r));
        
    }
    
    return ans;
    

}
