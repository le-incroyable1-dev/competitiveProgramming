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

static auto _______ = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        ll n = words[0].length();
        ll m = target.size();

        vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
        vector<vector<ll>> freq(n, vector<ll>(26, 0));

        fr(i, words[0].length()){
            fr(j, words.size()){
                freq[i][words[j][i]-'a']++;
            }
        }

        fr(i, m+1) dp[0][i] = 0LL;
        fr(j, n+1) dp[j][0] = 1LL;

        rep(i, 1, n){
            rep(j, 1, m){
                (dp[i][j] += dp[i-1][j])%=mod;

                char req = target[j-1];
                int count = freq[i-1][req-'a'];
                (dp[i][j] += count * dp[i-1][j-1])%=mod;
            }
        }

        ll ans = dp[n][m]%mod;

        if(ans > INT_MAX) return INT_MAX;
        else return (int)ans;
    }
};

int main(){
    vector<string> w = {"acca","bbbb","caca"};
    string s = "aba";

    Solution sol;
    cout << sol.numWays(w, s) << "\n";
    return 0;
}
