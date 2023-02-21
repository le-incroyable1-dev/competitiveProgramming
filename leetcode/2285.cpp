#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& r) {
        
        ll ans = 0;
        
        int m = r.size();
        
        unordered_map<int, ll> mp;
        
        for(auto v : r){
            
            mp[v[0]]++;
            mp[v[1]]++;
            
        }
        
        vector<ll> v;
        for(auto p : mp){
            //cout << p.first << " " << p.second << "\n";
            v.push_back(p.second);
        }
        
        int cur = n;
        
        sort(v.rbegin(), v.rend());
        
        for(auto val : v){
            ans += val*cur;
            cur--;
        }
        
        
        return ans;
        
    }
};
