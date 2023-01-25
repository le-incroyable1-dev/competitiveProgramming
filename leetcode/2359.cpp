class Solution {
public:

    void populateDistance(vector<int> &g, vector<bool> &vis, int node, int dist, vector<int> &v){

        v[node] = dist;
        vis[node] = true;

        if(g[node] >= 0 && !vis[g[node]])
        populateDistance(g, vis, g[node], dist+1, v);

        return;

    }

    int closestMeetingNode(vector<int>& g, int node1, int node2) {
        
        int res = INT_MAX;
        int ans = -1;

        int n = g.size();

        // vector<int> g[n];
        // for(int i =0; i < n; ++i)
        // g[i].push_back(edges[i]);

        vector<bool> vis(n, false);
        vector<int> v1(n, -1);
        vector<int> v2(n, -1);

        populateDistance(g, vis, node1, 0, v1);
        for(int i = 0; i < n; ++i) vis[i] = false;
        populateDistance(g, vis, node2, 0, v2);

        // for(auto val : v1) cout << val << " ";
        // cout << "\n";
        // for(auto val : v2) cout << val << " ";
        

        for(int i = 0; i < n; ++i){
            if(v1[i] != -1 && v2[i] != -1){
                if(max(v1[i], v2[i]) < res){
                    res = max(v1[i], v2[i]);
                    ans = i;
                }
            }
        }

        return ans;

    }
};
