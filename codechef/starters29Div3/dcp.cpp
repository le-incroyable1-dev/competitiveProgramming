// Decomposition Reaction Problem Code: DCP

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
#define itr(type) type::iterator itr
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


void sol(ll n, ll m, vi amounts, unordered_map<ll, vpi> mymap){
    
    //cout << "hello" << endl;

    unordered_map<ll, vpi>::iterator itr;

    fr(i, n){
        itr = mymap.find(i);

        if(itr != mymap.end()){
            //cout << "found" << endl;
            ll curamt = amounts.at(i);
            amounts.at(i) = 0;

            fr(j, itr->second.size()){
                amounts.at(itr->second.at(j).second) = (amounts.at(itr->second.at(j).second) + curamt*(itr->second.at(j).first))%mod;
            }
            
            //cout << curamt << endl;
        }
    }
    
    //cout << "hello" << endl;

    for(auto el : amounts){
        cout << el%mod << endl;
    }

    //cout << endl;

    return;

}



int main(void){
    
    fast;

    //test(t){

        ll n;
        ll m;
        cin >> n >> m;

        vi amounts;
        ll ele;

        fr(i, n){
            cin >> ele;
            amounts.pb(ele);
        }

        unordered_map<ll, vpi> mymap;
        //unordered_map <ll, vpi> map1;
        ll cnum;
        ll dnum;
        

        fr(i, m){

            cin >> cnum >> dnum;

            ll fp = cnum-1;
            vpi v;

            fr(j, dnum){

                ll num1;
                ll num2;
                cin >> num1 >> num2;

                v.pb(mp(num1, num2-1));

            }

            mymap.insert(mp(fp, v));

        }



        /*
        unordered_map<ll, vpi>::iterator itr;

        itr = mymap.begin();

        while(itr != mymap.end()){
            cout << itr->first << endl;
            itr++;
        }
        */
        

        sol(n, m, amounts, mymap);
    //}

    return 0;
    
}
