/*
In the gym, Chef prefers to lift at least W grams during a bench press and if that's impossible, Chef considers his workout to be incomplete and feels bad.

The rod weighs Wr grams and there are N other weights lying on the floor that weigh w1,w2,...,wN grams. To maintain balance and to ensure that there is no unnecessary load due to torque, it's important that the weights added to the left side are symmetric to the weights added to the right side. It is not required to use all of the weights. It is also not required to use any weights at all, if Chef feels satisfied lifting only the rod.

For example:

1 2 2 1 |Rod Center| 1 1 1 3 is a wrong configuration, but

1 2 3 1 |Rod Center| 1 3 2 1 is a right configuration.

Find whether Chef will be able to collect the required weights to feel satisfied.

Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains two lines of input.
The first line contains three space-separated integers N,W,Wr.
The second line contains N space-separated integers w1,w2,…,wN.
Output
For each test case, output the answer in a single line: "YES" if Chef will be satisfied after his workout and "NO" if not (without quotes).

You may print each character of each string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).
*/

#include <iostream>
using namespace std;

#define ll long long int

//MERGE SORT GFG
void merge(ll arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(ll arr[],int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
//



void generateAns(ll n, ll w, ll wr, ll *wts)
{
    
    if(wr >= w)
    {
        cout << "YES";
        return;
    }
    
    mergeSort(wts, 0, n-1);
	    
    ll adds = 0;
    
    for(int i = 0; i < n-1; i++)
    {
        
            if(wts[i] == wts[(i+1)])
            {
                adds += wts[i];
                i++;
            }
        
        
    }
    
    adds = adds + adds;
    ll total = adds + wr;
    
    if(total >= w)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    
    
    return;
}

int main() {
	// your code goes here
	ll t;
	ll n ,w, wr;
	
	
	cin >> t;
	
	while(t--)
	{
	    cin >> n;
	    cin >> w;
	    cin >> wr;
	    const ll num = n;
	    if(n > 0)
	    {
	        ll *wts = new ll[num];
	        
	        for(int i = 0; i < n; i++)
	        {
	            cin >> wts[i];
	        }
	    
	    
	        generateAns(n, w, wr, wts);
	    }
	    else
	    {
	        cout << "NO";
	    }
	
	    
	    cout << endl;
	    
	}
	
	return 0;
}
