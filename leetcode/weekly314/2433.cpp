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
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> arr(n, -1);
        arr[0] = pref[0];

        rep(i, 1, n-1){
            int prev = pref[i-1];
            int target = pref[i];
            int res = 0;

            if(prev == 0){
                arr[i] = target;
                continue;
            }
            else if(target == 0){
                arr[i] = prev;
                continue;
            }
            
            //cout << target << " " << prev << endl;

            

            for(int index = 0; index <= 31; index++){

//                 if(check == 0)
//                 break;
                
                

                int to_set = (1 << index) & target;
                to_set /= pow(2, index);
                int cur = (1 << index) & prev;
                cur /= pow(2, index);
                
                //cout << to_set << " " << cur << endl;
                if(to_set == 0){
                    if(cur == 1)
                    res += pow(2, index);
                }
                else if(to_set == 1){
                    if(cur == 0)
                    res += pow(2, index);
                }
                
                
            }
        

            arr[i] = res;
        
        }
        
        return arr;
    }
};
