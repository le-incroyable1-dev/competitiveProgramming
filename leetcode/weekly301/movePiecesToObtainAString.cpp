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
//#define itr(type) type::iterator itr
//#define tn TreeNode*
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};

// "_L__R__R_"
// "L______RR"

class Solution {
public:
    bool canChange(string start, string target) {
        
        
        ll n = start.length();
        
        if(n == 1)
            return start[0] == target[0];
        
        //cout << "passed" << endl;
        
        ll lc = 0;
        ll rc = 0;
        fr(i, n){
            if(start[i] == 'L')
            lc++;
            else if(start[i] == 'R')
            rc++;

            if(target[i] == 'L')
            lc--;
            else if(target[i] == 'R')
            rc--;
        }

        if(lc != 0 || rc != 0)
        return false;
        
        //cout << "passed" << endl;

        fr(i, n){
            if(start[i] == 'L')
            lc++;
            else if(start[i] == 'R')
            rc++;
        }
        
        char *arr = new char[lc+rc];

        ll k = 0;
        fr(i, n){
            if(start[i] != '_'){
                arr[k] = start[i];
                k++;
            }
        } 

        k = 0;

        fr(i, n){
            if(target[i] != '_'){
                if(arr[k] != target[i])
                return false;
                else
                k++;
            }
        }

        //delete(arr);
        
        //cout << "passed" << endl;

        set<ll> rs;
        set<ll> ls;

        fr(i, n){
            if(start[i] == 'L')
            ls.insert(i);
            else if(start[i] == 'R')
            rs.insert(i);
        }

        set<ll>::iterator ritr, litr;
        ritr = rs.begin();
        litr = ls.begin();

        fr(i, n){
            if(target[i] == 'L'){
                if(*litr < i)
                return false;
                else
                litr++;
            }
            else if(target[i] == 'R'){
                if(*ritr > i)
                return false;
                else
                ritr++;
            }
        }

        return true;

    }
};
