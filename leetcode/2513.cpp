#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

class Solution {
public:

    ll gcd(ll a, ll b){
        if(b == 0)
        return a;

        return gcd(b, a%b);
    }

    ll lcm(ll a, ll b){
        return (a/gcd(a,b))*b;
    }

    ll res(ll n1, ll d1){
        ll x = (d1*n1)/(d1-1);
        if(x%d1 == 0)
        x -= 1;

        return x;
    }

    int minimizeSet(int d1, int d2, int n1, int n2) {
        ll l = lcm(d1, d2);
        cout << l << "\n";

        cout << res(n1, d1) << "\n" << res(n2, d2) << "\n" << res(n1+n2, l) << "\n";

        ll ans = max(res(n1, d1), max(res(n2, d2), res(n1+n2, l)));

        if(ans > INT_MAX)
        return INT_MAX;
        else
        return (int)ans;
    }
};
