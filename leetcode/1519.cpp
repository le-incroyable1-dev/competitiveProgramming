#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:

    vector<int> helper(int n, vector<int> *tree, string &l, int node, vector<bool> &vis, vector<int> &ans){
        vector<int> v(26, 0);

        vis[node] = true;

        v[l[node] - 'a']++;
        vector<int> nv;

        for(auto val : tree[node]){

            if(vis[val])
            continue;

            nv = helper(n, tree, l, val, vis, ans);

            for(int i = 0; i < 26; ++i)
            v[i] += nv[i];

            nv.clear();
        }

        ans[node] = v[l[node]-'a'];
        return v;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> tree[n];

        for(auto v : edges){
            tree[v[0]].push_back(v[1]);
            tree[v[1]].push_back(v[0]);
        }

        vector<bool> vis(n, false);
        vector<int> ans(n, 0);
        vector<int> v = helper(n, tree, labels, 0, vis, ans);
        
        return ans;
    }
};
