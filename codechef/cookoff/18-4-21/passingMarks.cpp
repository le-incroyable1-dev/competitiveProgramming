#include <iostream>
using namespace std;

void passed(int *input)
{
    if(input[4] >=input[0] && input[5] >=input[1] && input[6] >=input[2])
    {
        int tot = input[4] + input[5] + input[6];
         if(tot >= input[3])
         {
             cout << "YES";
             return;
         }
    }
    
    cout << "NO";
    return;
}

int main() {
	// your code goes here
	
	// INPUT 
	
	
	int t;
	cin >> t;
	const int num = t;
	
	int **inputCollections = new int*[num];
	
	for(int i = 0; i < t; i++) 
	{
	    inputCollections[i] = new int[7];
	}

	
	 int x;
	 
	for(int i = 0; i < t; i++)
	{
	     cout << endl;
	    for(int j = 0; j < 7; j++)
	    {
	       
	        cin >> x;
	        inputCollections[i][j] = x;
	    }
	    
	   
	}
	
   
	
	
	//OUTPUT
	for(int i = 0; i < t; i++)
	{
	    passed(inputCollections[i]);
	    cout << endl;
	}
	
	
	

	return 0;
}



