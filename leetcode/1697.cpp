#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:

    vector<int> parent;
    vector<ll> size;

    void make_set(int v){
        parent[v] = v;
        size[v] = 1LL;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b){
        int x = find_set(a);
        int y = find_set(b);

        if(x == y) return;

        if (size[x] < size[y])
            swap(x, y);
        parent[y] = x;
        size[x] += size[y];
    }

    static bool cmp(vector<int> &v1, vector<int> &v2){
        return v1[2] <= v2[2];
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {

        for(int i = 0; i < queries.size(); ++i) queries[i].push_back(i);
        int qs = queries.size();
        vector<bool> ans(qs, false);

        parent.resize(n); size.resize(n);
        for(int i = 0; i < n; ++i) make_set(i);

        sort(queries.begin(), queries.end(), cmp);
        sort(edges.begin(), edges.end(), cmp);
        int ptr = 0;

        for(auto q : queries){

            int lim = q[2];

            while(ptr < edges.size() && edges[ptr][2] < lim){
                union_sets(edges[ptr][0], edges[ptr][1]);
                ++ptr;
            }

            int s = q[0];
            int e = q[1];

            bool res = (find_set(s) == find_set(e));
            ans[q[3]] = res;
        }

        return ans;

    }
};
