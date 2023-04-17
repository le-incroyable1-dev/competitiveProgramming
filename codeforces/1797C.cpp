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


void sol(){

    ll n, k; cin >> n >> k;

    vector<vector<ll>> v(n+1, vi(n+1, -1));
    ll ele;
    rep(i, 1, n) rep(j, 1, n) cin >> ele, v[i][j] = ele;

    ll k1 = 0;
    //ll k2 = 0;

    rep(i, 1, n){
        rep(j, 1, n){
            ll ic, jc;
            ic = n+1-i;
            jc = n+1-j;

            if(v[ic][jc] != v[i][j]) k1++;
        }
    }

    k1 /= 2; // only half of these need to be changed

    if(k1 > k) cout << "NO\n";
    else{
        k -= k1;

        if(n%2 != 0) cout << "YES\n";
        else if(k%2 != 0) cout << "NO\n";
        else cout << "YES\n";
    }

    // fr(i, n){
    //     fr(j, n/2){
    //         ll ic, jc;
    //         ic = n/2 + (n/2 - i) - (n%2 == 0);
    //         jc = n/2 + (n/2 - j) - (n%2 == 0);

    //         if(v[ic][jc] != v[i][j]) k2++;
    //     }
    // }

    // bool b1 = false;
    // bool b2 = false;

    // if((k-k1) >= 0 && (((k-k1)%2)==0)) b1 = true;
    // if((k-k2) >= 0 && (((k-k2)%2)==0)) b2 = true;

    // if(b1||b2) cout << "YES\n";
    // else cout << "NO\n";

    return;
    
    
}



int main(void){

    fast;

    test(t){
        sol();
    } 

    
}
