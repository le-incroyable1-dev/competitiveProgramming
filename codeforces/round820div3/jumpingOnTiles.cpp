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

//INCOMPLETE

void sol(string &s){

    vector<pair<char, int>> v;
    int n = s.length();
    fr(i, n)
    v.pb(mp(s[i], i+1));
    sort(all(v));

    

    int tiles = 1;
    int cost = 0;

    int ci = -1;
    fr(i, n){
        if(v[i].second == 1){
            ci = i;
            break;
        }
    }

    set<int> si;
    si.insert(ci);

    vector<int> seq;

    while(1){

        seq.pb(v[ci].second);

        if(v[ci].second == n){
            break;
        }

        int ni = -1;
        int dif1 = INT_MAX;
        int dif2 = INT_MAX;
        int i1 = INT_MIN;
        int i2 = INT_MIN;

        if(si.find(ci-1) == si.end() && ci-1 >= 0){
            dif1 = abs(v[ci].first - v[ci-1].first);
            i1 = v[ci-1].second;
        }

        if(si.find(ci+1) == si.end() && ci+1 < n){
            dif2 = abs(v[ci].first - v[ci+1].first);
            i2 = v[ci+1].second;
        }

        if(dif1 < dif2)
        ni = ci-1;
        else if(dif1 > dif2)
        ni = ci+1;
        else{
            if(i1 > i2)
            ni = ci-1;
            else if(i1 < i2)
            ni = ci+1;
        }

        if(ni == ci-1){
            cost += dif1;
            si.insert(ci-1);
            //seq.pb(v[ci-1].second);
        }
        else{
            cost += dif2;
            si.insert(ci+1);
            //seq.pb(v[ci-1].second);
        }

        tiles++;
        ci = ni;
    }

    v.clear();
    si.clear();

    cout << cost << " " << tiles << endl;
    for(auto val : seq)
    cout << val << " ";

    seq.clear();

    cout << endl;
    return;

}



int main(void){
    
    fast;

    test(t){

        string s;
        cin >> s;

        sol(s);
    }
    
}
