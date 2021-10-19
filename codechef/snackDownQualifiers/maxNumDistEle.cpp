#include <bits/stdc++.h>
using namespace std;

#define ll long long int;

//INCOMPLETE

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
    unordered_set<int> s;

    ll res = 0;
    for (int i = 0; i < n; i++) {

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
    
    for(int i = 0; i < n; i++)
    {
        ele.insert(B[i]);
    }
    
    
}

int main() {
	
	ll t = 0;
	cin >> t;
	
	while(t)
	{
	    ll n = 0;
	    cin >> n;
	    ll *B = new ll[n];
	    
	    for(int i = 0; i < n; i++)
	    {
	        cin >> B[i];
	    }
	    
	    solve(n,B);
	    
	    cout << endl;
	    
	}
	
	return 0;
}
