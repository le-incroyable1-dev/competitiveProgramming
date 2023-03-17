#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    static bool compare(vector<int> &v1, vector<int> &v2){
        if(v1[1] < v2[1]) return true;
        else return false;
    }

    int findMinimumTime(vector<vector<int>>& t) {
        int n = t.size();
        sort(t.begin(), t.end(), compare);

        // for(auto v : t){
        //     cout << v[0] << v[1] << v[2] << "\n";
        // }
        
        vector<int> slots(2002, 0); 

        for(auto v : t){

            int s = v[0];
            int e = v[1];
            int d = v[2];

            for(int i = e; i >= s; i--){
                if(slots[i] == 1) d--;
            }


            while(d > 0){

                if(slots[e] == 0){
                    slots[e] = 1;
                    d--;
                }

                e--;
            }
            
        }


        int ans = 0;
        for(auto val : slots){
            //cout << val << " ";
            if(val == 1) ++ans;
        }

        return ans; 
    }
};
