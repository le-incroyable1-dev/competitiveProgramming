#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& g) {
        
    
        int n = g.size();
        int m = g[0].size();
        
        vector<vector<vector<ll>>> store(n, vector<vector<ll>>(m, vector<ll>(8, 0)));
        
        //up
        
        for(int col = 0; col < m; ++col){
            ll f = 0;
            ll t = 0;
            
            for(int row = 0; row < n; ++row){
                store[row][col][0] = f;
                store[row][col][1] = t;
                
                int num = g[row][col];
            
                while(num%5 == 0){
                    num/=5;
                    f++;
                }

                while(num%2 == 0){
                    num/=2;
                    ++t;
                }
                
            }
            
        }
        
        //down
        
        for(int col = 0; col < m; ++col){
            ll f = 0;
            ll t = 0;
            
            for(int row = n-1; row >= 0; row--){
                store[row][col][4] = f;
                store[row][col][5] = t;
                
                int num = g[row][col];
            
                while(num%5 == 0){
                    num/=5;
                    f++;
                }

                while(num%2 == 0){
                    num/=2;
                    ++t;
                }
            }
        }
        
        
        //right
        
        for(int row = 0; row < n; ++row){
            ll f = 0;
            ll t = 0;
            
            for(int col = m-1; col >= 0; col--){
                store[row][col][2] = f;
                store[row][col][3] = t;
                
                int num = g[row][col];
            
                while(num%5 == 0){
                    num/=5;
                    f++;
                }

                while(num%2 == 0){
                    num/=2;
                    ++t;
                }
            }
        }
        
        
        //left
        
        for(int row = 0; row < n; ++row){
            ll f = 0;
            ll t = 0;
            
            for(int col = 0; col < m; ++col){
                store[row][col][6] = f;
                store[row][col][7] = t;
                
                int num = g[row][col];
            
                while(num%5 == 0){
                    num/=5;
                    f++;
                }

                while(num%2 == 0){
                    num/=2;
                    ++t;
                }
            }
        }
        
        
        //cout << "hello" << "\n";
        
        ll ans = 0;
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                
                int num = g[i][j];
                
                ll cf = 0;
                ll ct = 0;
                
                while(num%5 == 0){
                    num/=5;
                    ++cf;
                }
                
                
                while(num%2 == 0){
                    num/=2;
                    ++ct;
                }
                
                for(int a = 0; a < 8; a+=2){
                    for(int b = a+2; b < 8; b+=2){
                        
                        
                        ll f = cf;
                        ll t = ct;
                        
                        f += store[i][j][a] + store[i][j][b];
                        t += store[i][j][a+1] + store[i][j][b+1];
                        
                        
                        
                        ll cur = min(f, t);
                        ans = max(ans, cur);
                        
                    }
                }
            }
        }
        
        
        if(ans > INT_MAX) return INT_MAX;
        return (int)ans;
        
        
    }
};
