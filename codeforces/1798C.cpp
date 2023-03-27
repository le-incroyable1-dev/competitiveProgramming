//author : aurav
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef unsigned long long ll;
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

    ll n; cin >> n;
    vector<ll> ab;
    vector<ll> av, bv;
    fr(i, n){
        ll a, b;
        cin >> a >> b;
        av.pb(a); bv.pb(b);
        ab.pb(a*b);
    }
    
    ////

    ll tags = n;

    ll cur_gcd = ab[0];
    ll cur_b_lcm = bv[0];
    ll count = 0;

    fr(i, n){
        if(i == 0) continue;

        cur_gcd = __gcd <ll> (cur_gcd, ab[i]);
        cur_b_lcm = (cur_b_lcm * bv[i])/(__gcd<ll> (cur_b_lcm, bv[i]));

        if(cur_gcd%cur_b_lcm == 0) ++count;
        else{
            tags -= count;
            count = 0;
            cur_b_lcm = bv[i];
            cur_gcd = ab[i];
        }
    }

    tags -= count;

    // fr(i, n){
    //     ll cur = ab[i];
    //     if(cur == 0) continue;
    //     ll mx_count = 0;
    //     unordered_map<ll, ll> m;
    //     ll match_gcd;
    //     fr(j, n){
    //         if(i == j) continue;
    //         if(ab[j] == 0) continue;
    //         ll nxt = ab[j];
    //         ll cur_gcd = __gcd <ll> (cur, nxt);

    //         if(cur_gcd%bv[i] != 0 || cur_gcd%bv[j] != 0) continue;

    //         m[cur_gcd]++;
    //         if(m[cur_gcd] > mx_count) mx_count = m[cur_gcd], match_gcd = cur_gcd;
    //     }


    //     fr(j, n){
    //         if(i == j) continue;
    //         if(ab[j] == 0) continue;
    //         ll nxt = ab[j];
    //         ll cur_gcd = __gcd <ll> (cur, nxt);

    //         if(cur_gcd != match_gcd) continue;
    //         ab[j] = 0;
    //     }

    //     tags -= mx_count;
    //     m.clear();

    //     ab[i] = 0;
    // }

    cout << tags << "\n";
    return;

    
}



int main(void){

    fast;

    test(t){
        sol();
    } 

    
}
