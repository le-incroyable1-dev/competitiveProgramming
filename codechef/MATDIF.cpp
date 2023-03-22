#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t; cin >> t;
	
	while(t--){
	    int n; cin >> n;
	    int lim = n*n;
	    
	    int cur = 1;
	    
	    for(int i = 0; i < n; ++i){
	        for(int i = 0; i < n; ++i){
	            cout << cur << " ";
	            if(cur+2 > lim)
	            cur = 2;
	            else
	            cur += 2;
	        }
	        cout << "\n";
	    }
	}
	return 0;
}
