#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    unordered_map<int, vector<int>> m;

    int minJumps(vector<int>& v) {
        int n = v.size();
        if(n == 1) return 0;

        for(int i = 0; i < n; ++i) m[v[i]].push_back(i);

        queue<int> q;
        int ans = 0;
        q.push(0);
        vector<bool> vis(n, false);

        while(!q.empty()){
            int sz = q.size();

            for(int i = 0; i < sz; ++i){

                int cur = q.front(); q.pop();
                vis[cur] = true;

                if(cur == n-1) return ans;

                if(cur > 0)
                m[v[cur]].push_back(cur-1);

                if(cur+1 < n)
                m[v[cur]].push_back(cur+1);

                for(auto j : m[v[cur]]){

                    if(vis[j]) continue;

                    vis[j] = true;
                    q.push(j);
                }

                m[v[cur]].clear();
            }

            ans++;

        }
        
        return ans;
    }
};
