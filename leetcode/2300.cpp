#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        
        vector<int> ans;
        
        sort(potions.begin(), potions.end());
        
        for(auto s : spells){
            
            ll req = (ll)(ceil((long double)success/(long double)s));
            if(req > INT_MAX){
                ans.push_back(0);
                continue;
            }
            int pairs = (int)(potions.end() - lower_bound(potions.begin(), potions.end(), (int)req));
            ans.push_back(pairs);
        }
        
        return ans;
    }
};
