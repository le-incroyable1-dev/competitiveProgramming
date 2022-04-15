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
//#define itr(type) type::iterator itr
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};

/*
We will act greedily: we will make an array prev consisting of 26 elements, in which
 we will mark prev[i]=true if the letter is already encountered in the string, and 
 prev[i]=false otherwise. In the variable m we will store the length of the even string 
 that can be obtained from s. We will go through the string by executing the following algorithm:

if prev[i]=false, mark prev[i]=true.
if prev[i]=true, then we already have a pair of repeating characters to add to an even 
string — add 2 to the number m and clear the array used.
Clearing prev is necessary because both characters that will make up the next pair 
must be in the s string after the current character. In other words, if the last 
character in the current pair was st, then the first character in the new pair can be sk, where t<k<n.

Then we calculate the answer as n−m.
*/

//greedy


int sz = 26;
 
void solve(){
    string s;
    cin >> s;
    int m = 0, n = (int)s.size();
    vector<bool>prev(sz, false);
    for(auto &i : s){
        if(prev[i - 'a']){
            m += 2;
            for(int j = 0; j < sz; j++) prev[j] = false;
        }
        else prev[i - 'a'] = true;
    }
 
    cout << n - m << endl;
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}



/*
//INCORRECT
void sol(string s){

    ll ans = 0;
    ll n = s.length();

    if(n == 0){
        cout << 0 << endl;
        return;
    }
    else if(n == 1){
        cout << 1 << endl;
        return;
    }

    ll i = 0;

    unordered_map<char, int> alphs;
    unordered_map<char, int>::iterator itr;
    fr(i, n){
        itr = alphs.find(s.at(i));

        if(itr == alphs.end())
        alphs.insert(mp(s.at(i), 1));
        else
        itr->second++;
    }
    
    
    while(i < n){

        if(i == n-1){
            ans++;
            i++;
            continue;
        }

        if(s.at(i) == s.at(i+1)){

            itr = alphs.find(s.at(i));
            itr->second-=2;

            if(itr->second == 0)
            alphs.erase(itr);

            i += 2;
        }
        else{
            itr = alphs.find(s.at(i));
            
            if(itr->second == 1){
                ans++;
                alphs.erase(itr);
            }
            else if(itr->second > 1){
                itr->second--;
                char cur = s.at(i);
                i++;

                while(i<n && s.at(i) != cur){

                    itr = alphs.find(s.at(i));
                    itr->second--;

                    if(itr->second == 0)
                    alphs.erase(itr);

                    ans++;
                    i++;
                }
            }

            i++;
        }
    }

    cout << ans << endl;
    return;
}



int main(void){
    
    fast;

    test(t){

        string s;
        cin >> s;

        sol(s);
    }
    
}
*/