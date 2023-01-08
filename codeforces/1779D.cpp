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
//#define tn TreeNode*
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


void sol(int n, vector<int> &a, vector<int> &b, int m, vector<int> &x){


    fr(i, n){
        if(a[i] < b[i]){
            cout << "NO\n";
            return;
        }
    }

    map<int, int> mx;
    map<int, int>::iterator itr;
    fr(i, m)
    mx[x[i]]++;

    stack<int> s;

    fr(i, n){
        int cur = b[i];

        while(!s.empty() && s.top() < cur) s.pop();


        if(a[i] == cur) continue;

        if(s.empty() || s.top() != cur){
            itr = mx.lower_bound(cur);

            auto [v, c] = *itr;
            if(v != cur){
                cout << "NO\n";
                return;
            }
            else{
                s.push(v);
                if(c == 1)
                mx.erase(itr);
                else
                mx[cur]--;
            }
        }

    }

    cout << "YES\n";

    return;
    
}



int main(void){

    fast;

    test(t){
        int n; cin >> n;
        vector<int> a,b,x;
        int ele;

        fr(i, n){
            cin >> ele;
            a.pb(ele);
        }

        fr(i, n){
            cin >> ele;
            b.pb(ele);
        }

        int m; cin >> m;

        fr(i, m){
            cin >> ele;
            x.pb(ele);
        }

        sol(n, a, b, m, x);
    } 

    
}
