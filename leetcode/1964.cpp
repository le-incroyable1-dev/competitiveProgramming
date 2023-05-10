#include <bits/stdc++.h>
using namespace std;
#define pb push_back

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        
        int n = obstacles.size();
        
        vector<int> ans;
        vector<int> v(2*n);
        int pos = -1;
        int upto = 0;
        
        for(auto h : obstacles){
            
            //cout << h << "\n";
            //for(auto val : v) cout << val << " "; cout << "\n";
            if(pos == -1){
                pos = 0;
                v[pos] = h;
                ans.pb(pos+1);
                //cout << pos << "\n";
                //for(auto val : v) cout << val << " "; cout << "\n\n";
                continue;
            }
            
            upto = max(upto, pos+1);
            pos = upper_bound(v.begin(), v.begin() + upto, h) - v.begin();
            v[pos] = h;
            ans.pb(pos+1);
            //cout << pos << "\n";
            //for(auto val : v) cout << val << " "; cout << "\n\n";
        }
        
        return ans;
        
    }
};
