#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define mod 1000000007

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<ll, ll>> g[n];

        for(auto v : roads){
            g[v[0]].pb(mp(v[1], v[2]));
            g[v[1]].pb(mp(v[0], v[2]));
        }

        vector<bool> processed(n, false);
        vector<ll> time(n, LLONG_MAX);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

        //ways to reach node i = ways(i)
        vector<ll> ways(n, 0);
        ways[0] = 1;

        time[0] = 0;

        pq.push(mp(0, 0));

        //dijkstra sir oppp
        while(!pq.empty()){
            pair<ll, ll> cur = pq.top(); pq.pop();
            ll t = cur.first;
            ll node = cur.second;
            if(processed[node]) continue;

            processed[node] = true;
            ways[node]%=mod;

            for(auto [next, t1] : g[node]){
                if(t + t1 < time[next]){
                    time[next] = t + t1;

                    //found a shorter timed path, update the ways to reach next
                    ways[next] = ways[node];
                    pq.push(mp(t+t1, next));
                }
                else if(t + t1 == time[next])
                ways[next] = (ways[node] + ways[next])%mod;
                //found another path with the same time
            }

        }
        //////////////////

        // for(auto val : ways)
        // cout << val << " ";

        ll ans = ways[n-1]%mod;
        return (int)ans;
    }
};
