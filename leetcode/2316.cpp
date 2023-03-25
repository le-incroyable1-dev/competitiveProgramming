#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static auto _______ = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
}();


class Solution {

private:

    int find_set(int x, vector<int> &p){
        if(x == p[x]) return p[x];
        else return p[x] = find_set(p[x], p);
    }

    void join(int x, int y, vector<int> &p, vector<ll> &sz){
        int a = find_set(x, p);
        int b = find_set(y, p);

        if(a == b) return;

        if(sz[a] < sz[b]) swap(a, b);

        p[b] = a;
        sz[a] += sz[b];

        return;
    }

public:

    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<int> p(n); for(int i = 0; i < n; ++i) p[i] = i;
        vector<ll> sz(n); for(int i = 0; i < n; ++i) sz[i] = 1LL;

        for(auto e : edges) join(e[0], e[1], p, sz);

        vector<ll> szv;
        unordered_map<int, ll> m;
        for(int i = 0; i < n; ++i) m[find_set(i, p)]++;

        for(auto [par, count] : m) szv.push_back(count);

        sort(szv.begin(), szv.end());
        vector<ll> szvp;
        ll sum = 0;
        for(auto val : szv) sum += val, szvp.push_back(sum);

        ll ans = 0;

        for(int i = 1; i <  szv.size(); ++i){
            ans += (szv[i]*szvp[i-1]);
        }

        return ans;

    }
};
