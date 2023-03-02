//author : aurav
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


/*************************Recursive, TLE*********************************/

// #define SZ 1000000000
// vector<vector<vector<int>>> dp(SZ+1, vector<vector<int>>(SZ+1, vector<int>(2, -1)));

// int helper(int x, int y, int c){

//     if(c == 1){
//         if((x < 1 || y < 1) && (x < 2)) return c;

//         int res1 = c;
//         int res2 = c;

//         int co = c*(-1);

//         if(x >= 1 && y >= 1)
//         res1 = helper(x-1, y-1, co);

//         if(x >= 2)
//         res2 = helper(x-2, y, co);

//         if(res1 == co || res2 == co) return co;
//         else return c;
//     }
//     else{

//         if((x < 1 || y < 1) && (y < 2)) return c;

//         int res1 = c;
//         int res2 = c;

//         int co = c*(-1);

//         if(x >= 1 && y >= 1)
//         res1 = helper(x-1, y-1, co);

//         if(y >= 2)
//         res2 = helper(x, y-2, co);

//         if(res1 == co || res2 == co) return co;
//         else return c;

//     }

//     return 69;
// }


// void sol(int x, int y){

//     int res = helper(x,y,1);

//     if(res == 1) cout << "CHEFINA" << "\n";
//     else cout << "CHEF" << "\n";

//     return;
    
// }


void sol(int x, int y){

    if(x > y){
        int moves = y;
        int rem = x-y;

        if(moves%2 == 0){
            if(rem >= 2) cout << "CHEF\n";
            else cout << "CHEFINA\n";
        }
        else{
            cout << "CHEF\n";
        }
    }
    else if(x < y){
        int moves = x;
        int rem = y-x;

        if(moves%2 == 0){
            cout << "CHEFINA\n";
        }
        else{
            if(rem >= 2) cout << "CHEFINA\n";
            else cout << "CHEF\n";
        }
    }
    else{
        int moves = x;

        if(moves%2 == 0) cout << "CHEFINA\n";
        else cout << "CHEF\n";
    }
    
    return;
}

int main(void){

    fast;

    test(t){
        int x, y; cin >> x >> y;
        sol(x, y);
    } 

    
}
