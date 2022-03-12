#include <bits/stdc++.h>

//#define int long long
#define mp make_pair
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
typedef long double ld;
typedef long long ll;

using namespace std;

const ll inf = 1e9;
const ll M = 1e9;
const ld pi = atan2(0, -1);
const ld eps = 1e-4;

void solve() {
    int l, r, x;
    cin >> l >> r >> x;
    int ans = r / x + r % x;
    int m = r / x * x - 1;
    if(m >= l)ans = max(ans, m / x + m % x);
    cout << ans;
}

bool multi = true;

int main(void) {
    //freopen("in.txt", "r", stdin);
    //freopen("in.txt", "w", stdout);
    int t = 1;
    if (multi) {
        cin >> t;
    }
    for (; t != 0; --t) {
        solve();
        cout << "\n";
    }
    return 0;
}


/*
ll func(ll x, ll a){
    return floor(x/a) + x%a ;
}

void sol(ll l, ll r, ll a){

    ll s = max(((ll)(floor(r/a))*a)-1, l);
    
    ll maxval = LLONG_MIN;
    ll curval;

    while(s <= r){

        curval = func(s, a);

        if(curval > maxval)
        maxval = curval;

        s++;
    }

    cout << maxval << endl;
    return;
}



int main(void){

    //inn;
    //outt;

    fast;
    test(t){
        ll l, r, a;

        cin >> l >> r >> a;

        sol(l, r, a);
    }
}

*/
