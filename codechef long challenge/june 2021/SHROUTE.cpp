/*
There are N cities in Chefland numbered from 1 to N and every city has a railway station. Some cities have a train 
and each city has at most one train originating from it. The trains are represented by an array A, where Ai=0 means 
the i-th city doesn't have any train originating from it, Ai=1 means the train originating from the i-th city is 
moving right (to a higher numbered city), and Ai=2 means the train originating from the i-th city is moving left (to a lower numbered city).

Each train keeps on going forever in its direction and takes 1 minute to travel from the current station to the next one. 
There is a special station at city 1 which lets travellers instantaneously teleport to any other station that currently 
has a train. Teleportation and getting on a train once in the city both take 0 minutes and all trains start at time 0.

There are M travellers at city 1, and the i-th traveller has destination city Bi. They ask Chef to guide them to teleport 
to a particular station from which they can catch a train to go to their destination in the least time possible. In case 
it's not possible for a person to reach his destination, print −1.

Note: The input and output of this problem are large, so prefer using fast input/output methods.

Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains three lines of input.
The first line contains two integers N, M.
The second line contains N integers A1,A2,…,AN.
The third line contains M integers B1,B2,…,BM.
Output
For each test case, output M space-separated integers C1,C2,…,CM, where Ci is the minimum time required by the 
i-th traveller to reach his destination and if the i-th traveller can't reach his destination, Ci=−1.

Constraints
1≤N,M≤10^5
0≤Ai≤2
1≤Bi≤N
The sum of N over all test cases is at most 10^6.
The sum of M over all test cases is at most 10^6.
*/


// SHOWING TLE ERROR
#include <iostream>
using namespace std;
#define ll long long int


void calcAns(ll n, ll m, int *a, ll *b)
{
    //int *c = new int[m];
    ll dest;
    
    for(int i = 0; i < m; i++)
    {
        dest = b[i];
        ll ni,pi,ci;
        
        ci = dest-1;
        
        if(a[ci] != 0)
        {
            cout << 0 << " ";
            continue;
        }
        
        for(ll i = 1; i < n; i++)
        {
            ni = ci+i;
            pi = ci-i;
            
            
            if(ni >= n && pi < 0)
            {
                cout << -1 << " ";
                break;
            }
            
            if(ni < n)
            {
                if(a[ni] == 2)
                {
                    cout << i << " ";
                    break;
                }
            }
            
            if(pi >= 0)
            {
                if(a[pi] == 1)
                {
                    cout << i << " ";
                    break;
                }
            }
            
            
            
        }
    
    }
    
    return;
}

int main() {
	// your code goes here
	
	int t;
	ll n,m;
	
	cin >> t;
	
	while(t--)
	{
	    cin >> n >> m;
	    
	    int *a = new int[n];
	    for(ll i = 0; i < n; i++)
	    {
	        cin >> a[i];
	    }
	    
	    ll *b = new ll[m];
	    for(int i = 0; i < m; i++)
	    {
	        cin >> b[i];
	    }
	    
	    //cout << "hello";
	    calcAns(n,m,a,b);
	    
	    cout << endl;
	}
	
	return 0;
}
