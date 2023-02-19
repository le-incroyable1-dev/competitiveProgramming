#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& v1, vector<vector<int>>& v2) {
  
        map<int, int> m;
        
        for(auto v : v1) m[v[0]] += v[1];
        for(auto v : v2) m[v[0]] += v[1];
        
        vector<vector<int>> ans;
        
        for(auto p : m) ans.push_back({p.first, p.second});
        return ans;
        
    }
};
