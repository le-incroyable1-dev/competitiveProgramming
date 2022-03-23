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
#define vpi vector< pii >c
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


//INCOMPLETE
bool isPalindrome(string S)
{
    // Stores the reverse of the
    // string S
    string P = S;
 
    // Reverse the string P
    reverse(P.begin(), P.end());
 
    // If S is equal to P
    if (S == P) {
        // Return "Yes"
        return true;
    }
    // Otherwise
    else {
        // return "No"
        return false;
    }
}

bool isRegular(string s){
    ll c1 = 0;
    ll c2 = 0;

    fr(i, s.length()){

        if(s[i] == '(')
        c1++;
        else
        c2++;
    }

    return c1==c2;
}

void sol(ll n, string s){

    ll c = 0;
    ll r = s.length();
    ll cur = 2;
    ll removed = 0;
    string prefix = "";

    while(removed <= r){

        prefix = s.substr(0, cur);

        if(isRegular(prefix) && isPalindrome(prefix)){
            c++;
            s = s.substr(cur-1, s.length()-cur);
            cur = 2;
            removed += 2;
        }
        else{
            cur += 2;
        }

    }

    cout << c << " " << r-removed << endl;

}



int main(void){
    
    fast;

    test(t){
        ll n;
        cin >> n;

        string s;
        cin >> s;

        sol(n,s);
    }
    
}
