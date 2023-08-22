class Solution {
public:
    int longestEqualSubarray(vector<int>& v, int k) {
        
        int n = v.size();
        if(n == 1) return 1;
        unordered_map<int, vector<int>> m;
        
        for(int i = 0; i < n; ++i) m[v[i]].push_back(i);
        
        
        int max_len = 1;
        for(auto p : m){
            
            vector<int> v = p.second;
            //for(auto u : v) cout << u << " "; cout << "\n";
            
            if(v.size() == 1){ max_len = max(max_len, 1); continue; }
            
            vector<int> del , pre;
            for(int i = 1; i < v.size(); ++i) del.push_back(v[i] - v[i-1] - 1);
            
            int pre_sum = 0;
            for(auto val : del) pre_sum += val, pre.push_back(pre_sum);
            
            for(int i = 0; i < pre.size(); ++i){
                int cur_len = 0;
                int dels = pre[i];
                if(dels <= k) cur_len = i - 0 + 2;
                else{
                    
                    int j = lower_bound(pre.begin(), pre.end(), dels - k) - pre.begin();
                    
                    //cout << i << " " << j << "\n";
                    
                    if(j == i){
                        if(del[i] <= k) cur_len = 2;
                        else cur_len = 1;
                    }
                    else cur_len = i - j + 1;
                }
                
                max_len = max(max_len, cur_len);
            }
            
            continue;
        }
        
        return max_len;
        
    }
};
