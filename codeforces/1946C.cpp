//author: auravaces
#include<bits/stdc++.h>
using namespace std;
#define mod 1e9 + 7
#define pb push_back
#define mp make_pair
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
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};

//#define ln ListNode*
//#define tn TreeNode*
// -_ -_

pii traverse(vvi &t, ll x, ll n, ll i, ll prev){

    ll components = 0;
    ll contributions = 1; // self node contribution

    // root node
    if(prev == -1){
        //bool found = false;
        for(auto nxt : t[i]){
            pii cur = traverse(t, x, n, nxt, i);
            components += cur.first;
            contributions += cur.second;
        }

        if(contributions >= x){
            ++components;
            contributions = 0;
        }

        return {components, contributions};
    }


    for(auto nxt : t[i]){

        if(nxt == prev) continue;
        
        pii cur = traverse(t, x, n, nxt, i);
        components += cur.first;
        contributions += cur.second;
    }

    if(contributions >= x){
        ++components;
        contributions = 0;
    }
    
    pii res= {components, contributions};
    return res;
}

bool possible(vvi &t, ll x, ll k, ll n){
    pii res = traverse(t, x, n, 1, -1);
    return res.first >= k + 1;
}

void sol(){

    ll n, k; cin >> n >> k;
    vvi t(n + 1); //tree t
    fr(i, n - 1){
        ll u, v; cin >> u >> v;
        t[u].pb(v); t[v].pb(u);
    }

    ll l = 1; ll r = n;
    ll ans = 1;

    //1 is root
    while (l <= r){
        ll x = l + (r - l) / 2;

        if(possible(t, x, k, n)){ ans = max(ans, x); l = x + 1; }
        else r = x - 1;
    }

    cout << ans << '\n';
    return;
}



void solx(){

    

    return;
}

// -_


int main(void){

    fast; 
    // solx();
    test(t){
        sol();
    }
}
