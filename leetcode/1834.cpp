#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for(int i = 0 ; i < n; ++i)
        tasks[i].push_back(i);

        sort(tasks.begin(), tasks.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        int i = 0;
        ll t = tasks[0][0];

        vector<int> ans;

        while(i < n){

            if(pq.empty() && t < tasks[i][0])
            t = (ll)tasks[i][0];

            //cout << t << " ";
            while(i < n && tasks[i][0] <= t){
                pq.push(make_pair(tasks[i][1], tasks[i][2]));
                ++i;
            }

            //cout << i << "\n";
            if(!pq.empty()){
                pair<int, int> cur = pq.top(); pq.pop();

                
                t += (ll)cur.first;
                ans.push_back(cur.second);
            }
        }

        while(!pq.empty()){
            pair<int, int> cur = pq.top(); pq.pop();
            ans.push_back(cur.second);
        }

        return ans;
    }
};
