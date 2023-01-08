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


void sol(int n, int m, vector<int> &v){

    ll ops = 0;

    if(n == 1){
        cout << 0 << "\n";
        return;
    }

    if(v[m-1] > 0 && m-1 > 0){
        v[m-1] *= -1;
        ops++;
    }

    vi pre(n, 0);
    ll sum = 0;

    fr(i, n){
        sum += v[i];
        pre[i] = sum;
    }

    ll min_sum = INT_MAX;

    fr(i, m){
        min_sum = min(min_sum, pre[i]);
    }


    while(min_sum < pre[m-1]){
        int x;
        fr(i, m){
            if(pre[i] < pre[m-1])
            x = i;
        }

        priority_queue<pair<int, int>> pq;

        rep(j, x+1, m-1){
            pq.push(mp(v[j], j));
        }

        int cur = pre[m-1];

        while(cur > min_sum && !pq.empty()){
            auto [t, index] = pq.top(); pq.pop();
            if(t > 0){
                cur -= 2*t;
                ++ops;
                v[index] *= -1;
            }
        }

        sum = 0;

        fr(i, n){
            sum += v[i];
            pre[i] = sum;
        }

        min_sum = INT_MAX;

        fr(i, m){
            min_sum = min(min_sum, pre[i]);
        }
    }

    
    rep(i, m, n-1){
        min_sum = min(min_sum, pre[i]);
    }

    while(min_sum < pre[m-1]){

        int ci;
        int cur = pre[m-1];

        int cur_min;
        rep(i, m, n-1){
            if(pre[i] < cur){
               ci = i;
               cur_min = pre[i];
               break; 
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        rep(i, m, ci){
            pq.push(mp(v[i], i));
        }

        while(cur > cur_min && !pq.empty()){
            auto [t, index] = pq.top(); pq.pop();
            
            if(t < 0){
                v[index] *= -1;
                ++ops;
                cur_min -= 2*t;
            }
        }

        sum = 0;

        fr(i, n){
            sum += v[i];
            pre[i] = sum;
        }

        min_sum = INT_MAX;

        rep(i, m, n-1){
            min_sum = min(min_sum, pre[i]);
        }

    }
    cout << ops << "\n";

    return;
    
}



int main(void){

    fast;

    
    test(t){
        int n, m; cin >> n >> m;
        vector<int> v;
        int ele;

        fr(i, n){
            cin >> ele;
            v.pb(ele);
        }


        sol(n, m, v);
    } 

    
}
