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

int solve(int l, int r, vi &arr) {
	
    if (r - l == 1) return 0;
	
    int mid = (l + r)/2;


	int max_left = *max_element(arr.begin() + l, arr.begin() + mid);
	int max_right = *max_element(arr.begin() + mid, arr.begin() + r);
    
	int ans = 0;


	if (max_left > max_right) {
		++ans;
		for (int i = 0; i < (mid - l); ++i)
			swap(arr[l + i], arr[mid + i]);
	}


	return solve(l, mid, arr) + solve(mid, r, arr) + ans;
}

void sol(){

    ll m; cin >> m;
    vi p; ll ele; fr(i, m) cin >> ele, p.pb(ele);
    ll p1 = 0; ll p2 = log2(m);


    //////

    int ops = solve(0, m, p);
    if(!is_sorted(p.begin(), p.end())){
        cout << -1 << "\n"; return;
    }

    cout << ops << "\n"; return;

}



int main(void){

    fast;

    test(t){
        sol();
    } 

    
}
