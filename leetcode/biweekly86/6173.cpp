#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
typedef long double  ld;
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

// [[1,0,1,0,0,0,0,0],[0,0,0,1,1,0,0,1],[0,0,1,1,1,1,1,1],[0,1,0,0,1,1,0,1],[0,1,0,0,1,0,0,0]]
// 5
class Solution {
public:

    int ans = INT_MIN;
    void helper(unordered_set<int> s, vector<vector<int>> &mat, int cols, int idx){

        if(idx == mat[0].size())
        return;

        if(s.size() == cols){

            int m = mat.size();
            int n = mat[0].size();

            int count = m;

            fr(i, m){
                fr(j, n){
                    if(mat[i][j] == 1){
                        if(s.find(j) == s.end()){
                            count--;
                            break;
                        }
                    }
                }
            }

            ans = max(ans, count);
            return;
        }

        helper(s, mat, cols, idx+1);
        s.insert(idx);
        helper(s, mat, cols, idx+1);

        return;
    }

    int maximumRows(vector<vector<int>>& mat, int cols) {

        unordered_set<int> s;
        helper(s, mat, cols, 0);
        return ans;
    }
};
