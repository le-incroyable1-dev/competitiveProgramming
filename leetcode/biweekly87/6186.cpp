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
long long powerof2[] ={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


class Solution {
public:
    
    vector<int> smallestSubarrays(vector<int>& nums) {
        
        vector<int> ans;
        int mxval = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        
        if(mxval == 0){
            fr(i, n)
            ans.pb(1);
            
            return ans;
        }
        
        vector<vector<int>> v(n, vector<int>(32, -1));
            
        for(int i = n-1; i >= 0; i--){
            int cur = nums[i];
            int cmx = INT_MIN;
            int index = 31;
            
            for(;index >= 0; index--){
                if(cur & 1 == 1){
                    v[i][index] = 0;
                }
                else if(i < n-1){
                    if(v[i+1][index] != -1)
                    v[i][index] = 1 + v[i+1][index];
                }
                
                //index--;
                cur = cur >> 1;
                cmx = max(cmx, max(1, v[i][index] + 1));
                
            }

            ans.pb(cmx);
        }

        reverse(all(ans));
        return ans;

    }
};
