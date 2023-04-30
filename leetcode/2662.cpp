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

    int sx, sy, tx, ty;

    static bool cmp(vector<int> &v1, vector<int> &v2){
        return mp(v1[2], v1[3]) < mp(v2[2], v2[3]);
    }

    // vector<vector<vector<int>>> dp;

    // int cost(int i, vector<vector<int>> &sr, int px, int py){

    //     if(dp[i][px][py] != -1) return dp[i][px][py];

    //     if(i == sr.size()){
    //         int c = abs(px-tx) + abs(py-ty);
    //         return dp[i][px][py] = c;
    //     }

    //     int res = INT_MAX;

    //     int tr = 0;
    //     int dtr = 0;

    //     vector<int> r = sr[i];
    //     int x1, y1, x2, y2;
    //     x1 = r[0]; y1 = r[1]; x2 = r[2]; y2 = r[3];

    //     tr += abs(px-x1) + abs(py-y1);
    //     tr += r[4];
    //     tr += cost(i+1, sr, x2, y2);

    //     dtr = cost(i+1, sr, px, py);

    //     res = min(res, tr);
    //     res = min(res, dtr);
    //     return dp[i][px][py] = res;
    // }

    map<vector<int>, int> m;

    int cost(int i, vector<vector<int>> &sr, int px, int py){

        if(m.find({i, px, py}) != m.end()) return m[{i, px, py}];

        if(i == sr.size()){
            int c = abs(px-tx) + abs(py-ty);
            return m[{i, px, py}] = c;
        }

        int res = INT_MAX;

        int tr = 0;
        int dtr = 0;

        vector<int> r = sr[i];
        int x1, y1, x2, y2;
        x1 = r[0]; y1 = r[1]; x2 = r[2]; y2 = r[3];

        tr += abs(px-x1) + abs(py-y1);
        tr += r[4];
        tr += cost(i+1, sr, x2, y2);

        dtr = cost(i+1, sr, px, py);

        res = min(res, tr);
        res = min(res, dtr);
        return m[{i, px, py}] = res;
    }

    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        
        sx = start[0]; sy = start[1];
        tx = target[0]; ty = target[1];

        //dp.resize(203, vector<vector<int>>(tx+3, vector<int>(ty+3, -1)));
        
        vector<vector<int>> sr;
        for(auto v : specialRoads){
            if(abs(v[0]-v[2]) + abs(v[1]-v[3]) <= v[4]) continue;
            sr.pb(v);
        }

        sort(sr.begin(), sr.end(), cmp);

        int n = sr.size();
        
        int mc = abs(sx-tx) + abs(sy-ty);
        mc = min(mc, cost(0, sr, sx, sy));

        return mc;
    }
};
