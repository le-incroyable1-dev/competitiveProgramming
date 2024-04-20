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

// - hyphen
// _ underscore

//#define ln ListNode*
//#define tn TreeNode*
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};
// -_

void sol(){

    ll n, k; cin >> n >> k;
    vi a(n); fr(i, n) cin >> a[i]; 

    ll i = 0; ll j = n - 1;
    ll sunk = 0;
    int turn = 1;

    while(k && i <= j){

        // one left only
        if(i == j){
            if(k >= a[i]) ++sunk; ++i;
            break;
        }

        // in case 0
        if(a[i] == 0){ ++sunk; ++i; continue; }
        if(a[j] == 0){ ++sunk; j--; continue; }

        // i turn
        if(turn == 1){
            if(a[i] <= a[j]){
                if(k >= 2 * a[i] - 1){
                    k -= ( 2 * a[i] - 1 );
                    ++sunk;
                    a[j] -= ( a[i] - 1 ); 
                    ++i; 
                    turn = 2;
                    continue;
                }
                else break;
            }
            else{
                if(k >= 2 * a[j]){
                    k -= 2 * a[j];
                    ++sunk;
                    a[i] -= a[j]; 
                    j--;
                    turn = 1;
                    continue;
                }
                else break;
            }
        }

        // j turn
        else{
                if(a[j] <= a[i]){
                if(k >= 2 * a[j] - 1){
                    k -= ( 2 * a[j] - 1 );
                    ++sunk;
                    a[i] -= ( a[j] - 1 ); 
                    j--; 
                    turn = 1;
                    continue;
                }
                else break;
            }
            else{
                if(k >= 2 * a[i]){
                    k -= 2 * a[i];
                    ++sunk;
                    a[j] -= a[i]; 
                    ++i;
                    turn = 2;
                    continue;
                }
                else break;
            }
        }

        continue;
    }
    

    //ll left = max(0LL, n - sunk);
    cout << sunk << "\n";
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
