#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:

    long long maxScore(vector<int>& v1, vector<int>& v2, int k) {
        
        int n = v1.size();

        vector<int> id(v1.size());
        iota(begin(id), end(id), 0);
        sort(begin(id), end(id), [&](int i, int j){ return v1[i] > v1[j]; });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        ll sum = 0;
        ll min;

        ll ans = INT_MIN;

        for(auto i : id){
            pq.push({v2[i], v1[i]});
            sum += v1[i];

            if(pq.size() == k){


                min = pq.top().first;

                //cout << "\n" << sum << " " << min << "\n";

                ll cur = sum * min;
                ans = max(ans, cur);

                sum -= pq.top().second;
                pq.pop();
            }

        }
        
        return ans;
    }
};
