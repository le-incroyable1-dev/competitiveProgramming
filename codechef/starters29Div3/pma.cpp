//Plusle and Minun on Array Problem Code: PMA

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


void swap(ll &a, ll &b){
    ll temp = a;
    a = b;
    b = temp;
}

void sol(vi v){

    ll n = v.size();
    ll max_val = 0;

    vpi pos;
    vpi neg;

    fr(i, n){
        if(i%2 == 0)
        pos.pb(mp(abs(v.at(i)), i));
        else
        neg.pb(mp(abs(v.at(i)), i));
    }

    sort(all(pos));
    sort(all(neg));

    ll i = 0;
    ll j = neg.size()-1;

    map<pii, ll> m;
    ll mapsize = 0;
    
    //map<pii, ll>::iterator itr;

    while(i < pos.size() && j >= 0){
        if(pos.at(i).first < neg.at(j).first){
            m.insert(mp(mp(pos.at(i).second, neg.at(j).second), neg.at(j).first - pos.at(i).first));
            mapsize++;
            i++;
            j--;
            continue;
        }
        else{
            j--;
            continue;
        }
    }

    ll max_dif = LLONG_MIN;
    pii max_pair;
    max_pair.first = 0;
    max_pair.second = 0;

    for(auto el : m){
        if(el.second > max_dif){
            max_dif = el.second;
            max_pair = el.first;
        }
    }

    swap(v.at(max_pair.first), v.at(max_pair.second));
    //cout << max_pair.first <<  endl << max_pair.second << endl;

    fr(i, n){
        //cout << abs(v.at(i)) << " : " << i << endl;
        if(i%2 == 0)
        max_val+=abs(v.at(i));
        else
        max_val-=abs(v.at(i));

        //cout << max_val << endl;
    }

    cout << max_val << endl;
    return;

}



int main(void){
    
    fast;

    test(t){

        ll n;
        cin >> n;

        vi v;
        ll ele;

        fr(i, n){
            cin >> ele;
            v.pb(ele);
        }

        sol(v);
    }
    
}