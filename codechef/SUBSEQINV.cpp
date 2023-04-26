//author : aurav
#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
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


void sol(){
    int n; cin >> n;
    vector<int> perm; int ele;
    fr(i, n) cin >> ele, perm.pb(ele);

    //////////////


    ll ways = 1;

    int cpos = 0;
    vector<int> l(n, 0);
    vector<int> r(n, 0);
    int cmax = 0;
    fr(i, n){
        if(perm[i] > cmax) l[i] = 1;
        cmax = max(cmax, perm[i]);
    }

    int cmin = INT_MAX;
    per(i, n-1, 0){
        if(perm[i] < cmin) r[i] = 1;
        cmin = min(cmin, perm[i]);
    }

    fr(i, n) if(l[i] == 1 && r[i] == 1) ++cpos;

    fr(i, cpos) (ways *= 2LL)%=mod;

    if(cpos == n) ways -= 1;

    ways %= mod;

    cout << ways << "\n"; return;
}



int main(void){

    fast;

    test(t){
        sol();
    } 

    
}
