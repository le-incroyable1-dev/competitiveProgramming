/*
Chef has two numbers N and M. Help Chef to find number of integer N-tuples (A1,A2,…,AN) 
such that 0≤A1,A2,…,AN≤2M−1 and A1&A2&…&AN=0, where & denotes the bitwise AND operator.

Since the number of tuples can be large, output it modulo 109+7.

Input
The first line contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two integers N and M.
Output
For each test case, output in a single line the answer to the problem modulo 10^9+7.

Constraints
1≤T≤10^5
1≤N,M≤10^6
*/

//INCOMPLETE SOLUTION
#include <iostream>
using namespace std;
#define ll long long int


ll calcAns(int n, int m)
{
    if(n == 1)
    return 1;
    
    
    
}

int main() {
	// your code goes here
	int t;
	ll n,m;
	ll modulo = (10^9)+7 ;
	
	cin >> t;
	
	while(t--)
	{
	    cin >> n >> m;
	    cout << calcAns(n,m)%modulo<<endl;
	}
	
	return 0;
}
