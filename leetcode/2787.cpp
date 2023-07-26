typedef long long ll;
#define mod 1000000007

class Solution {
public:
    
    vector<vector<int>> save;
    int solve(int n, int i, int &x, int &m){        
        if(n == 0) return 1;
        if(i > m) return 0;
        
        if(save[n][i] != -1) return save[n][i];
        
        ll ways = 0;
        
        (ways += solve(n, i+1, x, m))%=mod;
        
        if(n >= pow(i,x)) (ways += solve(n - pow(i, x), i+1, x, m))%=mod;
        
        return save[n][i] = (int)ways;
        
    }
    
    int numberOfWays(int n, int x) {
        int ways = 0;
        
        float p = 1.0/x;
        //cout << p << "\n";
        float m = pow(n, p);  
        
        
        //cout << n << " " << m << "\n";
        save.resize(n+2, vector<int>(m+2, -1));
        
        int root = m;
        ways = solve(n, 1, x, root);
        
        return ways;
    }
};
