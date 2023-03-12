#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    long long beautifulSubarrays(vector<int>& v) {
        
        unordered_map<int, ll> m;
        int n = v.size();
        
        int cur = 0;
        m[0]++;
        ll ans = 0;
        
        for(auto val : v){
            cur ^= val;
            if(m.find(cur) != m.end()) ans += m[cur];
            m[cur]++;
        }
        
        return ans;
        
    }
};
