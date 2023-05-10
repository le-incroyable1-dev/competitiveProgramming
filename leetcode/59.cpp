#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> mat;
    
    
    void fill(int s, int num, int i, int j){
        if(s == 0) return;
        else if(s == 1){ mat[i][j] = num; return;}
        
        int i1 = i;
        int j1 = j;
        
        for(;j1 < j + s - 1; ++j1) mat[i1][j1] = num, ++num;
        for(;i1 < i + s - 1; ++i1) mat[i1][j1] = num, ++num;
        for(;j1 > j; --j1) mat[i1][j1] = num, ++num;
        for(;i1 > i; --i1) mat[i1][j1] = num, ++num;
        
        //cout << s << " " << num << "\n";
        
        fill(s-2, num, i+1, j+1);
        return;
    }
    
    vector<vector<int>> generateMatrix(int n) {
        
        cout << flush;
        mat.resize(n, vector<int>(n, -1));
        int N = n*n;
        
        fill(n, 1, 0, 0);
        return mat;
    }
};
