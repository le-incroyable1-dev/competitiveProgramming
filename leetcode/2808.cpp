class Solution {
public:
    int minimumSeconds(vector<int>& nums) {

        vector<int> v = nums;
        for(auto val : nums) v.push_back(val);
        
        int n = v.size();
        if(*min_element(v.begin(), v.end()) == *max_element(v.begin(), v.end())) return 0;
        
        unordered_map<int, int> m;
        unordered_map<int, int> secs;
        
        for(int i = 0; i < n; ++i){
            int cur = v[i];
            if(m.find(cur) != m.end()){
                int s1 = abs(m[cur] - i);            
                int sec = s1/2;
                
                secs[cur] = max(secs[cur], sec);
                m[cur] = i;
                
            }else{
                
                m[cur] = i;
                secs[cur] = 0;
            }
        }
        
        
        int res = INT_MAX;
        for(auto &[num, sec] : secs) res = min(res, sec);
        return res;
        
    }
};
