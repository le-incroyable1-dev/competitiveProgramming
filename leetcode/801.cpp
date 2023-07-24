#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwap(vector<int>& v1, vector<int>& v2) {
        
        int n = v1.size();
        int swaps = 0;
        
        vector<vector<int>> min_swaps(n, vector<int>(2, -1));
        
        min_swaps[0][0] = 0;
        min_swaps[0][1] = 1;
        
        for(int i = 1; i < n; ++i){
            if(v1[i-1] < v1[i] && v2[i-1] < v2[i] && v1[i-1] < v2[i] && v2[i-1] < v1[i]){
                min_swaps[i][0] = min(min_swaps[i-1][0], min_swaps[i-1][1]);
                min_swaps[i][1] =min(min_swaps[i-1][0], min_swaps[i-1][1]) + 1;
            }
            else if(v1[i-1] < v1[i] && v2[i-1] < v2[i]){
                min_swaps[i][0] = min_swaps[i-1][0];
                min_swaps[i][1] = min_swaps[i-1][1] + 1;
            }
            else if(v1[i-1] < v2[i] && v2[i-1] < v1[i]){
                min_swaps[i][0] = min_swaps[i-1][1];
                min_swaps[i][1] = min_swaps[i-1][0] + 1;
            }
            else return -1; //not possible
        }
        
        
        swaps = min(min_swaps[n-1][0], min_swaps[n-1][1]);
        return swaps;        
        
    }
};
