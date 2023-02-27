#include <bits/stdc++.h>
using namespace std;

int Solution::maxProduct(const vector<int> &A) {
    //int p = 1;
    
    int n = A.size();
    if(n == 0)
    return 0;
    
    int maxp = A[0];
    int localMax = A[0];
    int localMin = A[0];
    
    for(int i = 1; i < n; i++){
        if(A[i] > 0){
            localMax = max(A[i], localMax * A[i]); 
            localMin = min(localMin * A[i], A[i]);
        }
        else{
            
            int localMaxNeg = min(A[i], localMax * A[i]);
            localMax = max(localMin * A[i], A[i]);
            localMin = localMaxNeg;
        }
        
        //cout << i << " " << localMin << " " << localMax << endl;
        
        maxp = max(maxp, localMax);
    }
    
    return maxp;
}
