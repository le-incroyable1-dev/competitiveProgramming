#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

class Solution {

public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {

        int n = p.size();

        vector<pii> vp;
        for(int i = 0 ;i < n; ++i) vp.emplace_back(c[i], p[i]);

        sort(vp.begin(), vp.end());

        priority_queue<int> pq;

        int j = 0;
        
        while(k--){

            while(j < n && vp[j].first <= w) pq.push(vp[j].second), ++j;

            if(pq.empty()) break;
            else{
                w += pq.top(); pq.pop();
            }
        }


        return w;
    }
};
