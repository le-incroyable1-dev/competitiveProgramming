//author : aurav
#include<bits/stdc++.h>
using namespace std;
#define mod 998244353

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



int calc(int num, int sz, int r, vector<vector<int>> &dp){

    if(dp[num][sz] != -1) return dp[num][sz];
    if(sz == 1) return dp[num][sz] = 1;

    int k = 2;
    int ans = 0;

    while(num*k <= r){
        (ans += calc(num*k, sz-1, r, dp))%=mod;
        ++k;
    }

    return dp[num][sz] = ans;
}

void sol(int l, int r){

    int cur = l;
    int sz = 0;
    while(cur <= r) ++sz, cur*=2;

    cout << sz << " ";

    int count = 0;

    int R = r;
    int L = l;
    int max_val = L;

    while(l <= r){
        int mid = l + (r-l)/2;

        if(mid * pow(2, sz-1) <= R) l = mid+1, max_val = max(max_val, mid);
        else r = mid-1;
    }

    vector<vector<int>> dp(1000001, vector<int>(21, -1));
   
    while(L <= max_val){
        (count += calc(L, sz, R, dp))%=mod;
        ++L;
    }

    dp.clear();
    
    cout << count << "\n";
    return;
    
}



int main(void){


    fast;

    test(t){
        int l, r; cin >> l >> r;
        sol(l, r);
    } 

    
}
