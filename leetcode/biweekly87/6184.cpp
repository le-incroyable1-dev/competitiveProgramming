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
    
    vector<int> md = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int getDay(string date, vector<int> &smd){
        int month = stoi(date.substr(0, 2));
        int days = stoi(date.substr(3));

        int day = 0;
        day += days;

        if(month >= 2)
        day += smd[month-2];

        return day;
    }
    

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        vector<int> smd;
        int sd = 0;

        for(auto days : md){
            sd += days;
            smd.pb(sd);
        }

        int aalice = getDay(arriveAlice, smd);
        int lalice = getDay(leaveAlice, smd);
        int abob = getDay(arriveBob, smd);
        int lbob = getDay(leaveBob, smd);
        
        

        int num_days = min(lbob, lalice) - max(abob, aalice) + 1;
        return max(0, num_days);

    }
};
