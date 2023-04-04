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

    ll n, x1, y1, x2, y2;
    cin >> n >> x2 >> y2 >> x1 >> y1;

    ll k = -1;

    ll c = n/2;

    ll k1, k2;

    if(x1 < c) k1 = c - x1;
    else if(x1 == c) k1 = 0;
    else if(x1 > c) k1 = x1 - c - 1;

    if(y1 < c) k2 = c - y1;
    else if(y1 == c) k2 = 0;
    else if(y1 > c) k2 = y1 - c - 1;

    k = max(k1, k2);

    ll energy = LLONG_MAX;

    ll xdif = 0;
    ll ydif = 0;
    ll com = 0;
    ll en = 0;

    //p1

    xdif = min(abs(x2-c+k), abs(x2-c-k-1));
    if(y2 < c-k || y2 > c+k+1) ydif = min(abs(y2-c+k), abs(y2-c-k-1));

    com = min(xdif, ydif);
    en += com;
    xdif -= com;
    ydif -= com;
    en += max(xdif, ydif);

    energy = min(energy, en);

    //p2

    xdif = 0;
    ydif = 0;
    com = 0;
    en = 0;

    ydif = min(abs(y2-c+k), abs(y2-c-k-1));
    if(x2 < c-k || x2 > c+k+1) xdif = min(abs(x2-c+k), abs(x2-c-k-1));

    com = min(xdif, ydif);
    en += com;
    xdif -= com;
    ydif -= com;
    en += max(xdif, ydif);

    energy = min(energy, en);
    
    //

    cout << energy << "\n";
    return;
    
}



int main(void){

    fast;

    test(t){
        sol();
    } 

    
}
