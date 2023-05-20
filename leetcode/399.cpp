#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


class Solution {
public:

    unordered_map<string, string> parent;
    unordered_map<string, double> div;
    unordered_map<string, double> vals;
    //unordered_map<string, vector<string>> g;

    void make_set(string v) {
        parent[v] = v;
    }

    string find_set(string v) {
        if (v == parent[v])
            return v;
        
        string x = v;
        string p = parent[x];

        double dval = 1;

        while(x != p){

            double cval;
            if(div.find(x+p) != div.end()) cval = div[x+p];
            else cval = div[p+x];

            dval *= cval;

            x = p;
            p = parent[x];
        }

        vals[v] = dval;
        return x;
    }

    void union_sets(string a, string b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
            parent[b] = a;
    }

    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {

        for(auto v : eq) make_set(v[0]), make_set(v[1]);
        for(auto v : eq) union_sets(v[0], v[1]);
        for(int i = 0; i < eq.size(); ++i) div[eq[i][0] + eq[i][1]] = values[i];

        vector<double> res;

        for(auto q : queries){
            if(q[0] == q[1]){ if(parent.find(q[0]) != parent.end()) { res.push_back(1); continue; } else { res.push_back(-1); continue; } }
            else if(parent[q[0]] != parent[q[1]]){ res.push_back(-1); continue; }

            double val = vals[q[0]]/vals[q[1]];
            res.push_back(val);
        }

        return res;
    }
};
