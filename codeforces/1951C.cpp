//author: auravaces
#include<bits/stdc++.h>
using namespace std;
#define mod 1e9 + 7
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
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};

//#define ln ListNode*
//#define tn TreeNode*
// -_ -_

void sol(){
    ll n, m, k; cin >> n >> m >> k;
    vi a(n); fr(i, n) cin >> a[i];

    ll x = k / m;
    ll rem = k % m;

    vi v = a; sort(all(v));
    multiset<ll> s; fr(i, x + (rem > 0)) s.insert(v[i]);

    ll maxi = v[x + (rem > 0) - 1];

    ll extra = 0;
    ll ans = 0;

    for(auto p : a){
        if(s.empty()) break;

        if(s.find(p) != s.end()){
            if(p  == maxi && rem > 0){
                ans += ( ( p + extra ) * rem);
                extra += rem;
                rem = 0; maxi = -1;
                s.erase(s.find(p));
            }
            else{
                ans += ( ( p + extra ) * m);
                extra += m;
                s.erase(s.find(p));
            }
        }

        continue;
    }

    cout << ans << "\n";

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
