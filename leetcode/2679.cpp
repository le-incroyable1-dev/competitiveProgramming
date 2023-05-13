class Solution {
public:
    int matrixSum(vector<vector<int>>& v) {
        
        int n = v.size();
        int m = v[0].size();
        
        int score = 0;
        
        for(int i = 0; i < n; ++i) sort(v[i].begin(), v[i].end());
        
        
        
        for(int j = m-1; j >= 0; j--){
            int cmax = INT_MIN;
            for(int i = 0; i < n; ++i){
                cmax = max(cmax, v[i][j]);
            }
            
            score += cmax;
            
        }
        
        return score;
        
    }
};
