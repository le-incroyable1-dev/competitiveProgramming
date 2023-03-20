#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    long long findScore(vector<int>& v) {
        ll score = 0;
        
        int n = v.size();
        unordered_set<int> marked;
        
        vector<pair<int, int>> vp;
        for(int i = 0; i < n; ++i) vp.emplace_back(v[i], i);
        
        sort(vp.begin(), vp.end());
        
        for(auto p : vp){
            ll cur = p.first;
            int index = p.second;
            
            if(marked.find(index) == marked.end()) score += cur;
            else continue;
            
            marked.insert(index);
            marked.insert(index-1);
            marked.insert(index+1);
            
            continue;
        }
        
        return score;
    }
};
