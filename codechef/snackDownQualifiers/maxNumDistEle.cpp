#include <bits/stdc++.h>
using namespace std;

#define ll long long int;

//NOT CHECKED YET

//optimized isPrime from GFG
bool isPrime(ll n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}


ll countDistinct(ll *arr, ll n)
{
    unordered_set<ll> s;

    ll res = 0;
    for (ll i = 0; i < n; i++) {

        if (s.find(arr[i]) == s.end()) {
            s.insert(arr[i]);
            res++;
        }
    }
 
    return res;
}

void solve(ll n, ll *B)
{
    unordered_set <ll> ele;
    
    for(ll i = 0; i < n; i++)
    {
        ele.insert(B[i]);
    }
    
    ll * Af = new ll[n];
    ll * As = new ll[n];
    
    ll * Cf = new ll[n];
    ll * Cs = new ll[n];
    
    ll reqPrime = 1;
    
    for(ll i = 2; i < n; i++)
    {
        if(isPrime(i) && ele.find(i) == ele.end())
        {
            reqPrime = i;
            break;
        }
    }
    
    for(ll i = 0; i < n; i++)
    {
        Af[i] = reqPrime;
    }
    
    reqPrime = 1;
    
    for(ll i = (n+1); i > n ; i++)
    {
        if(isPrime(i))
        {
            reqPrime = i;
            break;
        }
    }
    
    for(ll i = 0; i < n; i++)
    {
        As[i] = reqPrime;
    }
    
    for(ll i = 0; i < n; i++)
    {
        Cf[i] = Af[i] % B[i];
        Cs[i] = As[i] % B[i];
    }
    
    if(countDistinct(Cf, n) >= countDistinct(Cs, n))
    {
        for(ll i = 0; i < n; i++)
        cout << Af[i] << " ";
    }
    else
    {
        for(ll i = 0; i < n; i++)
        cout << As[i] << " ";
    }
    
    return;
}

int main() {
	
	ll t = 0;
	cin >> t;
	
	while(t)
	{
	    ll n = 0;
	    cin >> n;
	    ll *B = new ll[n];
	    
	    for(ll i = 0; i < n; i++)
	    {
	        cin >> B[i];
	    }
	    
	    solve(n,B);
	    
	    cout << endl;
	    
	    t--;
	}
	
	return 0;
}
