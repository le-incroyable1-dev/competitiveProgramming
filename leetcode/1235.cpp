#include <bits/stdc++.h>
using namespace std;
#define pip pair<int, pair<int, int>>

class Solution {
public:

    static bool compare(pip &p1, pip &p2){
        return (p1.first < p2.first);
    }

    int solve(vector<pair<int, pair<int, int>>> &vp, int index, int n, vector<int> &st, vector<int> &dp){

        if(dp[index] != -1)
        return dp[index];

        if(index >= n){
            dp[index] = 0;
            return 0;
        }

        int prof1 = 0;
        int prof2 = 0;

        pip cur = vp[index];
        int val = cur.second.second;
        int s = cur.first;
        int e = cur.second.first;

        prof1 = 0 + solve(vp, index+1, n, st, dp);
        int next_index;

        vector<int>::iterator lb;
        lb = lower_bound(st.begin(), st.end(), e);

        if(lb != st.end() && *lb == e)
        next_index = lb - st.begin();
        else
        next_index = upper_bound(st.begin(), st.end(), e) - st.begin();
        
        prof2 =  val + solve(vp, next_index, n, st, dp);

        int res = max(prof1, prof2);
        dp[index] = res;
        return res;
    }


    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        vector<pair<int, pair<int, int>>> vp;
        int n = startTime.size();

        for(int i = 0; i < n; ++i)
        vp.push_back(make_pair(startTime[i], make_pair(endTime[i], profit[i])));

        sort(vp.begin(), vp.end(), compare);

        vector<int> s;
        for(auto val : vp)
        s.push_back(val.first);

        // for(auto p : vp)
        // cout << p.first << " " << p.second << "\n";

        // return 0;

        vector<int> dp(n+3, -1);
        int ans = solve(vp, 0, n, s, dp);
        return ans;

    }
};
