class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        
        //bool res = false;
        int n = d.size();
        
        if(n == 1) return (d[0] == 0);
        else if(n == 2) return (d[0] == d[1]);
        
        int ex = d[0]^d[n-1];
        int mx = 0;
        
        for(int i = 1; i < n-1; ++i) mx ^= d[i];
        
        return (mx == ex);
    }
};
