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


class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int n = s.length();
        int sh[n];
        fr(i, n)
        sh[i] = 0;

        for(auto v : shifts){
            int apply;
            if(v[2] == 1)
            apply = 1;
            else
            apply = -1;
            
            sh[v[0]] += apply;
            if(v[1] < n-1)
            sh[v[1]+1] += -1*apply;
            
            // rep(i, v[0], v[1]){
            //     sh[i] += apply;
            // }
        }
        
        int pre_sum = 0;
        fr(i, n){
            pre_sum += sh[i];
            sh[i] = pre_sum;
            
            cout << sh[i] << " ";
        }
        
        cout << endl;
        
        

        fr(i, n){
            if(sh[i] == 0)
            continue;
            else if(sh[i] > 0){
                //s[i] += 'a' + (sh[i])%26;
                
                sh[i] %= 26;
                int k = 'z' - s[i];
                if(k >= sh[i])
                s[i] += sh[i];
                else{
                    s[i] = 'a' + sh[i] - k - 1;
                }
            }
            else{
                
                //s[i] =
                
                sh[i]*= -1;
                sh[i]%=26;
                int k = s[i] - 'a';
                if(k >= abs(sh[i]))
                s[i] -= abs(sh[i]);
                else{
                    s[i] = 'z' - (abs(sh[i]) - k - 1);
                }
            }
        }

        return s;
    
    }
};
