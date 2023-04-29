#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:

    vector<int> parent;
    vector<ll> size;

    void make_set(int v) {
        parent[v] = v;
        size[v] = 1LL;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }


    int numSimilarGroups(vector<string>& strs) {
        
        int n = strs.size();

        parent.resize(n);
        size.resize(n);
        for(int i = 0; i < n; ++i) make_set(i);


        for(int i = 0; i < n; ++i){
            string s = strs[i];
            
            for(int j = 0; j < n; ++j){
                if(find_set(j) == find_set(i)) continue;

                string cur = strs[j];

                int fault = 0;
                for(int k = 0; k < cur.length(); ++k) if(cur[k] != s[k]) ++fault;
                if(fault == 2 || fault == 0) union_sets(i, j);
            }
        }

        unordered_set<int> s;
        for(auto v : parent) s.insert(v);

        int grps = s.size();
        return grps;
    }
};
