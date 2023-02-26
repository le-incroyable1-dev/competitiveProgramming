#define pb push_back


class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& v) {
        
        vector<int> v1, v2;
        
        int n = v.size();
        
        int cur = 0;
        
        for(int i = 0; i < n; ++i){
            v1.pb(cur);
            cur += v[i];
            
        }
        
        cur = 0;
        
        for(int i = n-1; i >=0 ; i--){
            v2.pb(cur);
            cur += v[i];
            
        }
        
        reverse(v2.begin(), v2.end());
        
        vector<int> ans;
        
        for(int i = 0; i < n; ++i) ans.push_back(abs(v1[i]-v2[i]));
        
        return ans;
        
    }
};
