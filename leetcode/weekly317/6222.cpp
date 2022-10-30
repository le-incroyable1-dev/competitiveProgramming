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


class Solution {
public:

    int sd(ll n, ll val)
    {
        if (n < 10) {
            val = val + n;
            return val;
        }
        return sd(n / 10, (n % 10) + val);
    }

    int count_digits(ll n)
    {

        string num = to_string(n);
        return (int)num.size();
    }

    long long makeIntegerBeautiful(long long n, int target) {


        ll ans = -1;

        ll csum = sd(n, 0);
        int diff = target - csum;

        if(diff >= 0)
        return 0;
        else{
            diff = abs(diff);
            int digs = count_digits(n);

            string num = to_string(n);
            string cur;
            int sod = 0;
            per(i, digs-1, 0){

                cur = num[i] + cur;
                ll val = stoll(cur);

                sod += stoi(string(1, num[i]));

                ll x = pow(10, cur.length()) - val;
                
                //cout << cur << " " << val << " " << x << " " << diff << endl;

                if(sod-1 >= diff){
                    
                    //cout << csum << " " << sod << " " << endl;
                    ans = x;
                    return ans;
                }

            }
            

        }

        return ans;


    }
};
