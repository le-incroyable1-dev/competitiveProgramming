#include <bits/stdc++.h>
using namespace std;



class Solution {
    
public:

    int helper(vector<int> *pc, string &s, int node, int prev, int &ans){

        char cur = s[node];

        int upath = 1;
        int lp = 0;
        int slp = 0;

    
        for(auto next : pc[node]){

            if(next == prev)
            continue;

            if(s[next] == cur){
                int call = helper(pc, s, next, node, ans);
                continue;
            }

            

            int cur_path = helper(pc, s, next, node, ans);

            //int nlp, nslp;

            if(cur_path > lp){
                slp = lp;
                lp = cur_path;
            }
            else if(cur_path > slp)
            slp = cur_path;
            
        }

        ans = max(ans, lp+slp+1);
        //cout << ans << "\n";
        return lp+1;
    }

    int longestPath(vector<int>& parent, string s) {

        int n = s.length();
        vector<int> pc[n];

        for(int i = 1; i < parent.size(); ++i)
        pc[parent[i]].push_back(i);

        int ans = 1;
        int res = helper(pc, s, 0, -1, ans);
        return ans;
    }
};
