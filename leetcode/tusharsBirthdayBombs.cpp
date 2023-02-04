#include <bits/stdc++.h>
using namespace std;

vector<int> Solution::solve(int a, vector<int> &b) {
    
    vector<int> ans;
    int min_ele = *min_element(b.begin(), b.end());
    
    int max_hits = a/(min_ele);
    int hits = max_hits;
    int i = 0;
    int n = b.size();
    
    while(i < n){
        
        if(ans.size() == max_hits)
        break;
        
        if(a-b[i] >= (hits-1)*min_ele){
            a -= b[i];
            hits--;
            ans.push_back(i);
        }
        else
        ++i;
        
        
    }
    
    return ans;
}
