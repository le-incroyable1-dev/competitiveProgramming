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



static auto _______ = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
}();



class Solution {
public:

    
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>> &mat, vector<map<int, vector<pair<int, int>>>> &rmv, vector<map<int, vector<pair<int, int>>>> &cmv){

        int n = mat.size(); int m = mat[0].size();
        if(i == n || j == m) return dp[i][j] = 0;

        if(dp[i][j] != -1) return dp[i][j];

        int val = mat[i][j];
        int res = 1;

        vector<pair<int, int>> v;

        if(rmv[i].lower_bound(val+1) != rmv[i].end()) v = (*(rmv[i].lower_bound(val+1))).second;
        for(auto [pi, pj] : v){
            res = max(res, 1 + solve(pi, pj, mat, rmv, cmv));
        }


        if(cmv[j].lower_bound(val+1) != cmv[j].end()) v = (*(cmv[j].lower_bound(val+1))).second;
        for(auto [pi, pj] : v){
            res = max(res, 1 + solve(pi, pj, mat, rmv, cmv));
        }

        return dp[i][j] = res;
     
    }

    int maxIncreasingCells(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();
        dp.resize(n+1, vector<int>(m+1, -1));

        vector<map<int, vector<pair<int, int>>>> rmv;
        vector<map<int, vector<pair<int, int>>>> cmv;

        if(m == 1 && n == 1) return 1;
        int res = 1;

        rmv.resize(n);
        cmv.resize(m);

        fr(i, n){            
            fr(j, m) rmv[i][mat[i][j]].push_back({i, j});
        }

        fr(j, m){
            fr(i, n) cmv[j][mat[i][j]].push_back({i, j});
        }

        fr(i, n){fr(j, m){
            res = max(res, solve(i, j, mat, rmv, cmv));
        }}

        return res;
    }
};
