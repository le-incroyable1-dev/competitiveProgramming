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


void sol(int n, vector<int> &v){


    vector<int> count(n+1, 0);
    fr(i, n){
        count[v[i]]++;
        if(count[v[i]] > 2){
            cout << "NO\n"; return;
        }
    }
    count.clear();

    unordered_map<int, vector<int>> m;

    fr(i, n)
    m[v[i]].pb(i);

    vector<int> p(n, -1);
    vector<int> q(n, -1);
    vector<bool> pbv(n+1, false);
    vector<bool> qbv(n+1, false);

    pbv[0] = true; qbv[0] = true;

    for(int x = n; x >= 1; x--){
        for(auto i : m[x]){
            if(!pbv[x] && p[i] == -1){
                p[i] = x;
                pbv[x] = true;
            }
            else if(!qbv[x] && q[i] == -1){
                q[i] = x;
                qbv[x] = true;
            }
            else{
                cout << "NO\n"; return;
            }
        }
    }

    fr(i, n){

        if(p[i] != -1){
            int x = p[i];

            while(x > 0 && qbv[x]) x--;
            if(x == 0){
                x = INT_MAX;
                q[i] = x;
                break;
            }

            q[i] = x;
            qbv[x] = true;
        }
        else{
            int x = q[i];

            while(x > 0 && pbv[x]) x--;
            if(x == 0){
                x = INT_MAX;
                p[i] = x;
                break;
            }

            p[i] = x;
            pbv[x] = true;
        }
    }

    

    fr(i, n){
        if(max(p[i], q[i]) != v[i]){
            cout << "NO\n"; return;
        }
    }

    cout << "YES\n";
    for(auto val : p)
    cout << val << " ";
    cout << "\n";
    for(auto val : q)
    cout << val << " ";
    cout << "\n";


    return;

    
}



int main(void){


    fast;

    test(t){
        int n; cin >> n;
        vector<int> v;
        int ele;
        fr(i, n){
            cin >> ele;
            v.pb(ele);
        }
        sol(n, v);
    } 

    
}
