#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> ans;

    void trace(vector<vector<int>> &graph, int prev, int node, vector<int> cur_path, int n){
        
        cur_path.push_back(node);

        if(node == n-1){
            ans.push_back(cur_path);
            return;
        }

        for(auto next : graph[node]){
            if(next != prev)
            trace(graph, node, next, cur_path, n);
        }

        return;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> cur_path;
        trace(graph, -1, 0, cur_path, n);

        return ans;
    }
};
