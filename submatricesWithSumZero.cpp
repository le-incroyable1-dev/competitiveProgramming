#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int Solution::solve(vector<vector<int> > &v) {
    
    int n = v.size();
    if(n == 0) return 0;
    int m = v[0].size();
    if(m == 0) return 0;
    
    
    
    
    //2D prefix sum OP
    
    vector<vector<ll>> pre(n, vector<ll>(m, 0));
    pre[0][0] = v[0][0];
    
    
    for(int i = 1; i < n; ++i) pre[i][0] = pre[i-1][0] + v[i][0];
    for(int j = 1; j < m; ++j) pre[0][j] = pre[0][j-1] + v[0][j];
    
    for(int i = 1; i < n; ++i){
        for(int j = 1; j < m; ++j){
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + v[i][j];       
        }
    }
    
    // for(int i = 0; i < n; ++i){
    //     for(int j = 0; j < m; ++j){
    //         cout << pre[i][j] << " ";
    //     }
        
    //     cout << "\n";
    // }
    
    // cout << "\n";
    
    //
    
    ll ans = 0;
    for(int r1 = 0; r1 < n; ++r1){
        for(int r2 = r1; r2 < n; ++r2){
            
            unordered_map<ll, ll> mp;
            mp[0]++;
            
            for(int j = 0; j < m; ++j){
                
                ll cur = pre[r2][j];
                if(r1 > 0) cur -= pre[r1-1][j];
                
                if(mp.find(cur) != mp.end()){
                    ans += mp[cur];
                    //cout << r1 << " " << r2 << " " << j << "\n";
                }
                
                //if(cur == 0) ++ans;
                
                mp[cur]++;
            }
            
            mp.clear();
        }
    }
    
    if(ans > INT_MAX) return INT_MAX;
    else return (int)ans;
    
}
