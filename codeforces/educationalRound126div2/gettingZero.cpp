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
#define vi vector< int >
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
Note that 32768=215, so you can make any value equal to 0 by multiplying it by two 15 times, 
since (v⋅215)mod215=0. So, the answer for each value ai is at most 15.

Now, let's note that there is always an optimal answer that consists of: at first, 
add one cntAdd times, then multiply by two cntMul times — and cntAdd+cntMul is the 
minimum answer. In other words, let's just iterate over all cntAdd≤15 and cntMul≤15 and 
check that (v+cntAdd)⋅2cntMulmod32768=0. The answer is minimum cntAdd+cntMul among them.

To prove that it's optimal to add at first and only then to multiply, note that it's not 
optimal to add more than once after muptiplying (v→2v→2v+2 can be replaced by v→v+1→2(v+1)). 
So there is at most one +1 between two ⋅2, but it's not optimal to make even one +1 since we 
need to make v divisible by 215 and +1 break divisibility.
*/

void sol(vi v, ll n){
    

    fr(i, n){

        int ele = v.at(i);
        int lim = 32768;
        int ops1, ops2 = 0;

        int ans = 15;    

        fr(a, 16){
            fr(b, 16){
                ops1 = a;
                ops2 = b;

                int res = (ele+ops1)*pow(2, ops2);

                if(res%lim == 0)
                ans = min(ans, ops1+ops2);
            }
        }

        cout << ans << " ";
    }

    cout << endl;

    return;
}



int main(void){
    
    fast;

    //test(t){

        ll n;
        cin >> n;
        
        int ele;

        vi v;

        fr(i, n){
            cin >> ele;
            v.pb(ele);
        }
        
        sol(v, n);
    //}
    
}
