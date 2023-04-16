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

class Graph {
public:

    vector<vector<pair<int, int>>> g;
    int n;

    Graph(int n, vector<vector<int>>& edges) {
        g.resize(n);
        
        for (auto& e: edges) g[e[0]].push_back(make_pair(e[1], e[2]));
        this->n = n;
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int s, int e) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(mp(0, s));
        vector<int> cost(n, INT_MAX);
        vector<bool> vis(n, false);
        cost[s] = 0;

        while(!pq.empty()){
            pair<int, int> cur = pq.top(); pq.pop();
            int c = cur.first;
            int u = cur.second;
            vis[u] = true;


            for(auto v : g[u]){
                if(vis[v.first]) continue;
                
                if(c + v.second < cost[v.first]){
                    cost[v.first] = c + v.second;
                    pq.emplace(cost[v.first], v.first);
                }
            }


            continue;
        }

        return (cost[e] == INT_MAX ? -1 : cost[e]);

    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
