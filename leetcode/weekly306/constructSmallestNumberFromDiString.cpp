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

    void helper(string pattern, int index, string &result, vector<int> used, string cur){

        int n = pattern.length();

        if(index == n+1){
            result = (cur < result ? cur : result);
            return;
        }

//         if(index == n){
            
//         }

        if(index == 0){
            rep(i, 1, 9){
                string curnew = cur;
                curnew += to_string(i);
                used[i-1] = 1;
                helper(pattern, 1, result, used, curnew);
                
                used[i-1] = 0;
            }
        }
        else{
            ll num = stoll(string(1, cur[index - 1]));

            if(pattern[index - 1] == 'I'){
                
                rep(i, num+1, 9){
                    if(used[i-1] == 0){
                        string curnew = cur;
                        curnew += to_string(i);

                        used[i-1] = 1;
                        helper(pattern, index+1, result, used, curnew);
                        
                        used[i-1] = 0;
                    }
                }
                
                return;
            }
            else{

                rep(i, 1, num-1){
                    if(used[i-1] == 0){
                        string curnew = cur;
                        curnew += to_string(i);

                        used[i-1] = 1;
                        helper(pattern, index+1, result, used, curnew);
                        
                        used[i-1] = 0;
                    }
                }
                
                return;

            }
            
        }


        return;

    }

    string smallestNumber(string pattern) {

        string result = "987654321";
        vector<int> used(9, 0);
        string cur = "";
        helper(pattern, 0, result, used, cur);

        return result;
    }
};
