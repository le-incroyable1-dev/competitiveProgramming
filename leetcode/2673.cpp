#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    
    ll res = 0;

    ll solve(int i, int n, vector<int> &c){

        if(i > n) return 0LL;

        ll ls = solve(2*i, n, c);
        ll rs = solve(2*i + 1, n, c);

        res += abs(ls - rs);
        ll mx_path = c[i] + max(ls, rs);
        return mx_path;

    }
    
    
    int minIncrements(int n, vector<int>& cost) {
        
        vector<int> c; c.push_back(0);
        for(auto val : cost) c.push_back(val);
        solve(1, n, c);
        
        //cout << s << " " << ts << "\n";
        
        if(res > INT_MAX) return INT_MAX;
        else return (int)res;
    }
};
