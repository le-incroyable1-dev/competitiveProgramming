#include <bits/stdc++.h>
using namespace std;
#define mp make_pair

static auto _______ = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
}();


class Solution {
public:

    vector<int> ans;
    vector<vector<bool>> vis;

    vector<int> maxPoints(vector<vector<int>>& g, vector<int>& queries) {
        int n = g.size();
        int m = g[0].size();
        int k = queries.size();

        vector<pair<int, int>> v;
        for(int i = 0; i < k; ++i) v.emplace_back(queries[i], i);

        sort(v.begin(), v.end());
        ans.resize(k, 0);
        vis.resize(n, vector<bool>(m, false));
        //cout << "h";
        //collect(0, 0, m, n, g, v, 0);

        //min_pq
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({g[0][0],0,0}); vis[0][0] = 1;
        
        int cnt = 0;

        //bfs
        for(auto [val,idx] : v){            
            while(pq.size()){
                vector<int> cur = pq.top();
                int v = cur[0];
                int i = cur[1];
                int j = cur[2];

                if(v >= val) break;
                else pq.pop(), cnt++;

                if(i-1 >= 0 and !vis[i-1][j]) pq.push({g[i-1][j],i-1,j}), vis[i-1][j] = 1;
                if(j-1 >= 0 and !vis[i][j-1]) pq.push({g[i][j-1],i,j-1}), vis[i][j-1] = 1;
                if(i+1 <  n and !vis[i+1][j]) pq.push({g[i+1][j],i+1,j}), vis[i+1][j] = 1;
                if(j+1 <  m and !vis[i][j+1]) pq.push({g[i][j+1],i,j+1}), vis[i][j+1] = 1;
            }   
            ans[idx] = cnt;
        }
        
        return ans;
    }
};
