/*
Chef is planning a heist in the reserve bank of Chefland. They are planning to hijack the bank for D days and print the money. 
The initial rate of printing the currency is P dollars per day and they increase the production by Q dollars after every interval of d days. 
For example, after d days the rate is P+Q dollars per day, and after 2d days the rate is P+2Q dollars per day, and so on. 
Output the amount of money they will be able to print in the given period.

Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, four integers D,d,P,Q.
Output
For each test case, output in a single line the answer to the problem.

Constraints
1≤T≤105
1≤d≤D≤106
1≤P,Q≤106
*/
#include <iostream>
using namespace std;

#define ll long long int


ll calAns(ll a,ll b,ll P,ll Q, ll d)
{
    ll res = 0;
    
    res += d*((b*P) + ((Q*b*(b-1))/2));
    
    if(a != 0)
    {
        res += a*(P + (b*Q));
    }
    
    return res;
}

int main() {
	// your code goes here
	
	int t;
	
	ll D, d, P, Q;
	
	cin >> t;
	
	while(t--)
	{
	    cin >> D >> d >> P >> Q;
	    ll a = D%d;
	    ll b = D/d;
	    
	    cout << calAns(a,b,P,Q,d) << endl;
	}
	
	return 0;
}
