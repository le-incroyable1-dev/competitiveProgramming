#include <bits/stdc++.h>
using namespace std;

int rem = 0;

int fill(vector<int> &c, int u, int pre, vector<int> *g){
    int ct = 1;

    if(c[u] != -1) return c[u];

    for(auto v : g[u]){
        if(v == pre) continue;
        
        int cur = fill(c, v, u, g);
        ct += cur;

        if(cur >= 2 && cur%2 == 0) ++rem;
    }   

    return c[u] = ct;
}

int solve(int a, vector<vector<int>> &b) {

    int n = b.size();

    vector<int> g[a+2];
    for(auto v : b) g[v[0]].push_back(v[1]), g[v[1]].push_back(v[0]);

    vector<bool> vis(a+2, false);
    vector<int> count_1(a+2, -1);
    fill(count_1, 1, -1, g);

    return rem;

}

int main(){
    vector<vector<int>> b = {
        {1,2}//,
        // {1,3},
        // {1,4},
        // {3,5},
        // {4,6}
    };
    
    int a = 2;
    cout << solve(a, b) << "\n";
    return 0;
}
