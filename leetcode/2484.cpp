#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

class Solution {
public:
    int pre[10000][10][10], suf[10000][10][10];
    int countPalindromes(string s) {
        int n = s.length();
        ll res = 0;
        //fix center element
        vector<int> ct(10, 0);

        for(int i = 0; i < n; ++i){

            int cur = s[i] - '0';
            
            if(i > 0)
                for(int j = 0; j < 10; ++j){
                    for(int k = 0; k < 10; ++k){
                        pre[i][j][k] = pre[i-1][j][k];
                        if(k == cur) pre[i][j][k] += ct[j];
                    }
                }

            ++ct[cur];
        }

        for(int i = 0; i < 10; ++i) ct[i] = 0;

        for(int i = n-1; i >= 0; i--){

            int cur = s[i] - '0';
            
            if(i < n-1)
                for(int j = 0; j < 10; ++j){
                    for(int k = 0; k < 10; ++k){
                        suf[i][j][k] = suf[i+1][j][k];
                        if(k == cur) suf[i][j][k] += ct[j];
                    }
                }

            ++ct[cur];
        }

        ct.clear();

        for(int i = 2; i <= n-3; ++i){
            for(int j = 0; j < 10; ++j){
                for(int k = 0; k < 10; ++k){
                    (res += (ll)pre[i-1][j][k] * (ll)suf[i+1][j][k])%=mod;
                }
            }
        }

        if(res > INT_MAX) return res;
        else return (int)res;
    }
};
