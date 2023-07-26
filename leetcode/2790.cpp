typedef long long ll;

class Solution {
public:
    int maxIncreasingGroups(vector<int>& v) {
        int n = v.size();
        int res = 0;
        
        sort(v.begin(), v.end());
        ll add = 0;
        
        for(int i = 0; i < n; ++i){
            add += v[i];
            
            ll req = ((ll)res + 1LL) * ((ll)res + 2LL);
            req /= 2;
            
            if(add >= req) ++res;
            
        }
        
        
        return res;
    }
};
