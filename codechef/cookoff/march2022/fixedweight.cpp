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
#define itr(type) type::iterator itr
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};

/*
vector<ll> getDivisors(ll n)
{
    vi res;
    // Note that this loop runs till square root
    for (ll i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)
            res.pb(i);
            else{
                res.pb(i);
                res.pb(n/i);
            }
        }
    }

    return res;
}


void sol(ll n, ll x){

    vi divs = getDivisors(x);
    //sort(all(divs));

    fr(i, divs.size()){
        if(divs.at(i) <= n){

            ll cursize = divs.at(i);
            ll min = x/divs.at(i);

            if(min <= n && ((n-min+1) >= cursize)){
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
    return;
}

*/
void sol(ll n, ll x){

    for (ll i=1; i<=sqrt(x); i++)
    {
        if (x%i == 0)
        {
            if (x/i == i && i <= n){
                ll cursize = i;
                ll min = x/cursize;

                if(min <= n && ((n-min+1) >= cursize)){
                    cout << "YES" << endl;
                    return;
                }
            }
            else{
                ll cursize = i;
                ll min = x/cursize;

                if(cursize <= n && min <= n && ((n-min+1) >= cursize)){
                    cout << "YES" << endl;
                    return;
                }

                cursize = x/i;
                min = x/cursize;

                if(cursize <= n && min <= n && ((n-min+1) >= cursize)){
                    cout << "YES" << endl;
                    return;
                }

            }
        }
    }

    cout << "NO" << endl;
    return;
}



int main(void){
    fast;
    test(t){

        ll n, x;

        cin >> n >> x;

        sol(n, x);
    }
}
