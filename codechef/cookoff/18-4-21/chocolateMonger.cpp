#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/*
O(n^2)
int countDistinct(vector<int> *input, int n)
{
    int res = 1;
 
    // Pick all elements one by one
    for (int i = 1; i < n; i++) {
        int j = 0;
        for (j = 0; j < i; j++)
            if (input->at(i) == input->at(j))
                break;
 
        // If not printed earlier, then print it
        if (i == j)
            res++;
    }
    return res;
}
*/

//O(n)
int countDistinct(vector<int> *input, int n)
{
    // Creates an empty hashset
    unordered_set<int> s;
 
    // Traverse the input array
    int res = 0;
    for (int i = 0; i < n; i++) {
 
        // If not present, then put it in
        // hashtable and increment result
        if (s.find(input->at(i)) == s.end()) {
            s.insert(input->at(i));
            res++;
        }
    }
 
    return res;
}

void printDistinctFlavors(vector<int> *input)
{
    vector<int> *arr = new vector<int>();
    int x = input->at(1);
    int n = input->at(0);
    
    for(int i = 0; i < n; i++)
    {
        arr->push_back(input->at(i+2));
    }
    
    int distinct = countDistinct(arr, arr->size());
   
    int duplicates = n - distinct ;
    
      //cout << n << " " << x << " ";
   if(x <= duplicates)
   {
       cout << distinct;
   }
   else
   {
       cout << n-x;
   }
}

int main() {
	// your code goes here
	
	// INPUT
	int t;
	cin >> t;
	const int num = t;
	
	vector<int> **inputCollections = new vector<int>*[num];
	
	for(int i = 0; i < t; i++) 
	{
	    inputCollections[i] = new vector<int>();
	}
	
	int x;
	int n;
	
	for(int i = 0; i < t; i++)
	{
	    cout << endl;
	    cin >> n;
	    
	    inputCollections[i]->push_back(n);
	    
	   for(int j = 1; j < n+2 ; j++ )
	   {
	       cin >> x;
	       inputCollections[i]->push_back(x);
	       
	   }
	}
	

    // OUTPUT
    for(int i = 0; i < t; i++)
	{
	    printDistinctFlavors(inputCollections[i]);
	    cout << endl;
	}
	
	
	return 0;
}
