#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        //sweep-line
        for(auto q : queries){
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            
            //for every row, mark +1 where the submatrix starts
            //then mark -1 after it ends (according to the column)
            for(int r = r1; r <= r2; ++r){
                ans[r][c1] += 1;
                
                
                if(c2 + 1 < n)
                ans[r][c2+1] -= 1;
            }
        }

        //take the sum across the rows to get the final sweeped result
        for(int i = 0; i < n; ++i){
            for(int j = 1; j < n; ++j){
                ans[i][j] += ans[i][j-1];
            }
        }

        return ans;
    }
};
