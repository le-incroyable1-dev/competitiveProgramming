#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int maxProfit(vector<int>& p) {

        ll ans = 0;

        int n = p.size();
        ll cur_max = INT_MIN;

        for(int i = n-1; i >= 0 ; i--){
            ans = max(ans, cur_max-(ll)p[i]);
            cur_max = max(cur_max, (ll)p[i]);
        }

        return (int)ans;
        
    }
};
