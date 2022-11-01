#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void track(int i, int j, vector<vector<int>> &grid, int &col){

        int n = grid.size();
        int m = grid[0].size();

        if(i == n){
            col = j;
            return;
        }

        if(i < 0 || i >= n || j < 0 || j >= m)
        return;
        
        int cur = grid[i][j];

        if(cur == -1 && j == 0)
        return;
        else if(cur == 1 && j == m-1)
        return;
        else if(cur == -1 && grid[i][j-1] == 1)
        return;
        else if(cur == 1 && grid[i][j+1] == -1)
        return;
        else{
            if(cur == 1){
                track(i+1, j+1, grid, col);
            }
            else{
                track(i+1, j-1, grid, col);
            }
        }

        return;
    }

    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans;

        for(int j = 0; j < m; ++j){
            int i = 0;
            int col = -1;

            track(i, j, grid, col);

            ans.push_back(col);
        }

        return ans;
    }
};
