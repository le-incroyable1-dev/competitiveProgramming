//author : aurav
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
typedef long double ld;
#define pii pair<ll,ll>
#define vi vector< ll >
#define vvi vector< vi >
#define vpi vector< pii >
#define vvpi vector< vpi >
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define test(t) ll t;cin>>t;while(t--)
#define mem(a,b) memset(a,b,sizeof(a))
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b)))
//#define ln ListNode*
//#define tn TreeNode*
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


class Solution {
public:
    int cur_min = INT_MAX;
    vector<int> cur_path;
    unordered_map<int, int> ct;

    void move(int n, vector<int> *g, int pre, int u, int e, int cost, vector<int> &path, vector<int> &p){
        if(u == e){
            cost += p[e];
            path.pb(e);
            if(cost < cur_min) cur_min = cost, cur_path = path;
            path.pop_back();
            return;
        }

        cost += p[u];

        path.pb(u);
        for(auto v : g[u]){
            if(v == pre) continue;
            move(n, g, u, v, e, cost, path, p);
        }
        path.pop_back();

        return;
    }

    pair<int, int> solvePath(vector<int> &p, int u, int par, vector<int> *g){

        int half = (p[u]/2) * ct[u];
        int not_half = p[u] * ct[u];

        for(auto v  : g[u]){
            if(par == v) continue;

            pair<int, int> next = solvePath(p, v, u, g);
            half += next.second;
            not_half += min(next.first, next.second);
        }

        return {half, not_half};
    }

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& p, vector<vector<int>>& trips) {
        vector<int> g[n];
        for(auto v : edges) g[v[0]].pb(v[1]), g[v[1]].pb(v[0]);

        int m = trips.size();
        vector<int> paths[m];

        for(int i = 0; i < trips.size(); ++i){
            cur_min = INT_MAX;
            cur_path.clear();
            vector<int> t = trips[i];
            int s = t[0];
            int e = t[1];

            vector<int> path;
            move(n, g, -1, s, e, 0, path, p);
            paths[i] = cur_path;
        }

        unordered_set<int> banned;
        unordered_set<int> half;
        
        for(auto path : paths){
            for(auto v : path) ct[v]++;
        }

        pair<int, int> p1 = solvePath(p, 0, -1, g);
        int res = min(p1.first, p1.second);
        return res;

    }
};
