class Solution {
public:
    vector<int> decode(vector<int>& e, int first) {
        
        vector<int> ans;
        
        int cur = first;
        ans.push_back(first);
        
        int n = e.size();
        
        for(int i = 0; i < n; ++i){
            cur = cur^e[i];
            ans.push_back(cur);
        }
        
        return ans;
        
    }
};
