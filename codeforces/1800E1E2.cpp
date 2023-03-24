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


int find_set(int x, vector<int> &p){
    if(x == p[x]) return x;
    else return p[x] = find_set(p[x], p);
}

void join(int x, int y, vector<int> &p, vector<ll> &sz){
    int a = find_set(x, p);
    int b = find_set(y, p);

    if(a == b) return;

    if(sz[a] < sz[b]) swap(a, b);

    p[b] = a;
    sz[a] += sz[b];

    return;
}

void sol(){

    int n, k; cin >> n >> k;
    string s, t; cin >> s >> t;
    vector<int> p(n); fr(i, n) p[i] = i;
    vector<ll> sz(n); fr(i, n) sz[i] = 1LL;

    fr(i, n){
        if(i+k < n) join(i, i+k, p, sz);
        if(i+k+1 < n) join(i, i+k+1, p, sz);
    }

    unordered_map<char, unordered_map<int, int>> m;

    fr(i, n) m[s[i]][p[i]]++;
    
    fr(i, n){
        if(m[t[i]][p[i]] == 0){
            cout << "NO\n"; return;
        }

        m[t[i]][p[i]]--;
    }

    cout << "YES\n"; return;
}



int main(void){

    fast;

    test(t){
        sol();
    } 

    
}
