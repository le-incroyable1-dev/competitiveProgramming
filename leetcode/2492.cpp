#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

class Solution {
public:


    int find(vector<int> &par, int val){
        return par[val] == val ? val : find(par, par[val]);
    }

    void connect(vector<int> &par, vector<ll> &s, int a, int b){
        
        a = find(par, a);
        b = find(par, b);

        if(s[a] < s[b]){
            par[a] = b;
            s[b] += s[a];
        }
        else{
            par[b] = a;
            s[a] += s[b];
        }

        return;

    }

    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<int> par(n+1, 0);
        vector<ll> s(n+1, 0);

        for(int i = 0; i <= n; ++i){
            par[i] = i;
            s[i] = 1;
        }

        int res = INT_MAX;

        for(auto v : roads){
            connect(par, s, v[0], v[1]);
        }

        // for(auto e : par){
        //     cout << e << " ";
        // }

        // cout << "\n";

        int x = find(par, 1);

        for(auto v : roads){
            int a = v[0];
            int b = v[1];

            a = find(par, a);
            b = find(par, b);

            if(a == x || b == x)
            res = min(res, v[2]);
        }

        return res;
    }
};
