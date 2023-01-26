#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {

        vector<pair<int, int>> g[n];
        vector<int> price(n, INT_MAX);

        for(auto v : f){
            g[v[0]].push_back(make_pair(v[1], v[2]));
        }

        queue<vector<int>> q;
        int ans = INT_MAX;

        q.push({src, 0});
        vector<int> dist(n, INT_MAX);

        dist[src] = 0;
        //int stops = 0;

        while(!q.empty() && k >= 0){

            int sz = q.size();

            while(sz--){

                vector<int> cur = q.front(); q.pop();

                int node = cur[0];
                int d = cur[1];

                for(auto v : g[node]){
                    if(d + v.second  < dist[v.first]){
                        dist[v.first] = d + v.second;
                        q.push({v.first, dist[v.first]});
                    }
                }
            }

            k--;

            continue;
        }

        ans = dist[dst];

        if(ans == INT_MAX) return -1;
        return ans;

    }
};
