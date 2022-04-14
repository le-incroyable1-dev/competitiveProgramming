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
The first observation we need to solve this problem: the required height is 
either max or max+1, where max is the maximum initial height of some tree. 
We don't need heights greater than max+1, because, for example, if the height 
is max+2, we can remove some moves and get the answer for the height max. The 
same thing applies to all heights greater than max+1. Why do we even need the 
height max+1? In some cases (like [1,1,1,1,1,1,2]) the answer for the height max+1 
is better than the answer for the height max (in this particular case, it is 9 vs 11).

Now, we have two ways to solve the problem: either use some gross formulas, or 
just write a binary search on the answer. I won't consider the solution with 
formulas (but we have one), so let's assume we use binary search. Let the current 
answer be mid. Then let cnt1=⌈mid2⌉ be the number of +1 operations we can do and 
cnt2=⌊mid2⌋ be the number of +2 operations we can do. We can use +2 operations greedily 
and then just check if the number of +1 operations is sufficient to grow up the remaining heights.

Time complexity: O(nlogn) per test case.
*/


int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int n;
        scanf("%d", &n);
        vector<int> h(n);
        for (auto &it : h) {
            scanf("%d", &it);
        }
        
        int mx = *max_element(h.begin(), h.end());
        long long ans = 1e18;
        for (auto need : {mx, mx + 1}) {
            long long l = 0, r = 1e18;
            long long res = -1;
            while (l <= r) {
                long long mid = (l + r) >> 1;
                long long cnt1 = (mid + 1) / 2, cnt2 = mid - cnt1;
                long long need1 = 0;
                for (auto ch : h) {
                    long long cur = (need - ch) / 2;
                    if ((need - ch) % 2 == 1) {
                        ++need1;
                    }
                    if (cnt2 >= cur) {
                        cnt2 -= cur;
                    } else {
                        cur -= cnt2;
                        cnt2 = 0;
                        need1 += cur * 2;
                    }
                }
                if (need1 <= cnt1) {
                    res = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            ans = min(ans, res);
        }
        
        printf("%lld\n", ans);
    }
        
    return 0;
}

void sol(vi v, ll n){

    
}


/*
void sol(vi v, ll n){

    sort(all(v));
    //reverse(all(v));

    fr(i, n){
        v.at(i) = v.at(n-1) - v.at(i);
    }

    ll day = 1;

    while(v.at(0) != 0){

        if(day%2 == 0){

            if(v.at(0) == 1){
                day++;
                continue;
            }
            else{
                
                bool found = false;

                fr(i, n){
                    if(v.at(i) == 2){
                        v.at(i) -= 2;
                        found = true;
                        break;
                    }
                }

                if(!found)
                v.at(0) -= 2;
            }
        }
        else{

            bool found = false;

            fr(i, n){
                if(v.at(i) == 1){
                    v.at(i) -= 1;
                    //sort(v.begin(), v.end(), greater<>());
                    found = true;
                    break;
                }
        
            
            }

            if(!found)
            v.at(0) -= 1;

        }

        sort(v.begin(), v.end(), greater<>());

        day++;

    }

    cout << day-1 << endl;
}
*/

/*
int main(void){
    
    fast;

    test(t){

        ll n;
        cin >> n;

        ll ele;
        vi v;

        fr(i, n){
            cin >> ele;
            v.pb(ele);
        }

        sol(v, n);
    }
    
}
*/
