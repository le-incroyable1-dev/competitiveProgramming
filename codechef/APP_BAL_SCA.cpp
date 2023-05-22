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

    ll m, n; cin >> m >> n;
    ///

    if(n > m){ cout << "No\n"; return; }
    else if(n == m) { cout << "Yes\n"; return; }

    if(m%2 != 0) { cout << "No\n"; return; }
    else{
        ll num = m;
        ll tpow = 0;

        while(num%2 == 0) num/=2, ++tpow;
        ll rem = num;
        ll smallest_even = rem*2;

        if(n%2 == 0){
            if(n < smallest_even) cout << "No\n";
            else (n%smallest_even == 0) ? cout << "Yes\n" : cout << "No\n";
        }
        else{
            if(n < rem) { cout << "No\n"; return; }

            n -= rem;
            if(n == 0) { cout << "Yes\n"; return; }
            
            if(n < smallest_even) cout << "No\n";
            else (n%smallest_even == 0) ? cout << "Yes\n" : cout << "No\n";
        }

    }

    return;
}



int main(void){
    fast;
    test(t){
        sol();
    } 
}
