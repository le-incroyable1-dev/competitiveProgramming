#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
  if (b == 0LL)
    return a;
  return gcd(b, a % b);
}
 
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

int main() {
	// your code goes here
	ll t; cin >> t;
	while(t--){
	    ll a,b,c,d;
	    cin >> a >> b >> c >> d;
	    
	    if(b == d){
	        cout << 1 << "\n";
	        continue;
	    }
	    
	    
	    
	    ll rem = a%b;
	    
	    if(b-rem > 1 && d-rem > 1){
	        cout << 1 << "\n";
	        continue;
	    }
	    
	    ll lc = lcm(b, d);
	    
	    
	    ll ans = lc - rem;
	    cout << ans << "\n";
	    
	}
	return 0;
}
