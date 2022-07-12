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
//#define itr(type) type::iterator itr
//#define tn TreeNode*
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};

//recursive, TLE
class Solution {
public:

    void helper(int n, int maxValue, int left, vector<int> v, ll &ans){
        if(left == 0){
            ans++;
            ans %= mod;
            return;
        }

        if(left == n){
            for(int i = 1; i <= maxValue; ++i){
                v.pb(i);
                helper(n, maxValue, left-1, v, ans);
                v.pop_back();
            }
        }
        else{
            int sz = v.size();
            int prev = v[sz-1];

            for(int i = 1; i <= maxValue; ++i){
                if(i%prev == 0){
                    v.pb(i);
                    helper(n, maxValue, left-1, v, ans);
                    v.pop_back();
                }
            }
        }

        return;
    }

    void helper2(int n, int maxValue, int index, int* v, ll &ans){
        if(index == n){
            ans++;
            ans %= mod;
            return;
        }

        if(index == 0){
            for(int i = 1; i <= maxValue; ++i){
                v[index] = i;
                helper2(n, maxValue, index+1, v, ans);
                //v.pop_back();
            }
        }
        else{
            int prev = v[index-1];

            for(int i = 1; i <= maxValue; ++i){
                if(i%prev == 0){
                    v[index] = i;
                    helper2(n, maxValue, index+1, v, ans);
                }
            }
        }

        return;
    }

    int idealArrays(int n, int maxValue) {

        //vector<int> v;
        int *v = new int[n];
        ll ans = 0;
        int left = n;
        //helper(n, maxValue, left, v, ans);
        helper2(n, maxValue, 0, v, ans);
        
        ll res = ans%mod;
        if(res > INT_MAX)
        return INT_MAX;
        else
        return (int)res;
    }
};
