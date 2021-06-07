/*
Chefland has 2 different types of coconut, type A and type B. Type A contains only xa milliliters of coconut water and type B contains only xb grams of coconut pulp. Chef's nutritionist has advised him to consume Xa milliliters of coconut water and Xb grams of coconut pulp every week in the summer. Find the total number of coconuts (type A + type B) that Chef should buy each week to keep himself active in the hot weather.

Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, four integers xa, xb, Xa, Xb.
Output
For each test case, output in a single line the answer to the problem.
*/


#include <iostream>
using namespace std;


int calAns(int a, int b, int Xa, int Xb)
{
    int res = 0;
    
    res += Xa/a;
    res += Xb/b;
    
    if(Xa%a != 0)
    res++;
    
    if(Xb%b != 0)
    res++;
    
    return res;
}


int main() {
	// your code goes here
	
	int a,b,Xa,Xb;
	int t;
	
	cin >> t;
	
	while(t--)
	{
	    cin >> a >> b >> Xa >> Xb;
	    cout << calAns(a,b,Xa,Xb) << endl;
	}
	
	return 0;
}
