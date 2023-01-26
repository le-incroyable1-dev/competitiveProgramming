class Solution {
public:
    
    bool done = false;

    void helper(vector<int> v, int n, unordered_map<int, int> mp, int i, int m, vector<int> &ans){

        if(done) return;
        
        if(i == m){
            
            ans = max(ans, v);
            done = true;
            return;
        }
        
        if(v[i] != -1){
            helper(v, n, mp, i+1, m, ans);
            return;
        }
        
        for(int num = n; num >= 1; num--){
            
            if(mp[num]){
                
                if(num == 1){
                    v[i] = num;
                    mp[num]--;
                    helper(v, n, mp, i+1, m, ans);
                    v[i] = -1;
                    mp[num]++;
                    continue;
                }
                
                if(i+num < m && v[i+num] == -1){
                    mp[num]-=2;
                    v[i] = num;
                    v[i+num] = num;
                    helper(v, n, mp, i+1, m, ans);
                    mp[num]+=2;
                    v[i] = -1;
                    v[i+num] = -1;
                }
            }
        }
        
        return;
        
    }
    
    vector<int> constructDistancedSequence(int n) {
        
        int m = 2*n-1;
        unordered_map<int, int> mp;
        vector<int> v(m, -1);
        
        mp[1] = 1;
        
        for(int i = 2; i <= n; ++i){
            mp[i] = 2;
        }
        
        vector<int> ans(m, -1);
        
        helper(v,n,mp,0,m,ans);
        
        
        return ans;
        
        
        
    }
};
