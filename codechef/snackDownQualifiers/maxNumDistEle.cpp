#include <bits/stdc++.h>
using namespace std;

#define ll long long int

//INCOMPLETE

/*
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
*/

void solve(ll n, ll *B)
{
    ll * A = new ll[n];
    //ll * C = new ll[n];
    ll temp = 0;
    //ll distEle;
    unordered_set <ll> Cset;
    bool check = false;
    bool hasOne = false;
    
    for(int i = 0; i < n; i++)
    {
        if(B[i] == 1){
            hasOne = true;
            break;
        }
    }
    
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j <= 2*B[i]; j++)
        {
            
            if(hasOne && B[i] == 1)
            {
                check = true;
            }
            
            temp = j % B[i];
            if(Cset.find(temp) == Cset.end() || j == 2*B[i])
            {
                if(hasOne && check == false && j!=2*B[i])
                {
                    if(temp == 0)
                    {
                        continue;
                    }
                }
                
                A[i] = j;
                Cset.insert(temp);
                break;
            }
        }
        
    }
    
    for(ll i = 0; i < n; i++)
    {
        cout << A[i] << " ";
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
