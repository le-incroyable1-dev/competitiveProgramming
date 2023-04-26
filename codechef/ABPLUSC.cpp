#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	// your code goes here
	int t; cin >> t;
	ll lim = 1000000;
	while(t--){
	    ll x; cin >> x;
	    
	    if(x == 1LL){
	        cout << -1 << "\n"; continue;
	    }
	    
	    if(x-1LL <= lim){
	        cout << 1 << " " << 1 << " " << x-1 << "\n";
	    }
	    else{
	        ll fp = x - lim;
	        ll f1 = (ll)sqrtl(fp) + (ll)(floor(sqrtl(fp)) != sqrtl(fp));
	        
	        ll rem_new = x - (f1*f1);
	        
	        if(rem_new > 0){
	            cout << f1 << " " << f1 << " " << rem_new << "\n";
	        }
	        else{
	            ll f2 = f1 - 1;
	            rem_new = x - (f1*f2);
	            if(rem_new > lim) cout << -1 << "\n";
	            else cout << f1 << " " << f2 << " " << rem_new << "\n";
	        }
	    }
	}
	return 0;
}
