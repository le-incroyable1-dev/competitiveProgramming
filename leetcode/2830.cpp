class Solution {
public:
    
    vector<int> dp;
    int profit(int i, vector<vector<int>> &offers){
        
        int m = offers.size();
        
        if(dp[i] != -1) return dp[i];
        
        if(i == m) return dp[i] = 0;
        
        int res = 0;
        
        res = max(res, profit(i+1, offers));
    
        int gold = offers[i][2];
        int end = offers[i][1];
        vector<int> v = {end+1, end+1, INT_MIN};
        int n_i = lower_bound(offers.begin(), offers.end(), v) - offers.begin();
        
        res = max(res, gold + profit(n_i, offers));
        
        return dp[i] = res;
    }
    
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        int m = offers.size();
        dp.resize(m+1, -1);
        
        int max_profit = profit(0, offers);
        return max_profit;
    }
};
