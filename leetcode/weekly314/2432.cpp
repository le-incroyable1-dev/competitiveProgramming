#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        
        int mx_id = -1;
        int mx_time = INT_MIN;
        int len = logs.size();
        int st = 1;
        
        for(int i = 0; i < len; ++i){
            
            int end = logs[i][1];
            
            if((end-st+1) > mx_time){
                mx_time = end-st+1;
                mx_id = logs[i][0];
            }
            else if((end-st+1) == mx_time){
                
                if(logs[i][0] < mx_id)
                mx_id = logs[i][0];
            }
            
            st = end+1;
        }
        
        return mx_id;
    }
};
