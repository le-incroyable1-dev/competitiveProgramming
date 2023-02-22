#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool canShip(int val, int d, vector<int> &w){

        int cur = 0;
        int days = 1;

        //cout << val << "\n";
        
        for(auto wt : w){

            if(wt > val) return false;
            
            if(cur + wt > val){
                days++;
                cur = wt;
            }
            else cur += wt;

           
        }

        return (days <= d);

    }

    int shipWithinDays(vector<int>& w, int d) {
        
        int r = 0;
        for(auto val : w) r+=val;

        int l = (r/d) + (r%d!=0);

        //cout << l << " " << r << "\n";

        int ans = r;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(canShip(mid, d, w)){
                r = mid-1;
                ans = min(ans, mid);
            }
            else l = mid+1;
        }



        return ans;


    }
};
