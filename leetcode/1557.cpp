#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

        vector<bool> in(n, false);
        for(auto v : edges) { in[v[1]] = true; }

        vector<int> ans;

        for(int i = 0; i < n; ++i){
            if(in[i] == false) ans.push_back(i);
        }

        return ans;
    }
};
