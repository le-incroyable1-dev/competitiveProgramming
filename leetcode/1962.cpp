#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> pq(piles.begin(), piles.end());
        int ans = 0;
        for(auto val : piles)
        ans += val;

        while(pq.size() > 0 && k--){
            int cur = pq.top();
            pq.pop();

            int remove = cur/2;
            cur -= remove;
            ans -= remove;

            if(cur > 0)
            pq.push(cur);
        }

        return ans;

    }
};
