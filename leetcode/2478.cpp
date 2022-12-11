#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

class Solution {
public:

    bool isPrime(char c){
        return (c == '2' || c == '3' || c == '5' || c == '7');
    }

    int helper(string &s, int k, int minLength, int start, vector<vector<int>> &dp){

        int n = s.length();

        if(dp[k][start] != -1)
        return dp[k][start];

        if(k == 0){
            dp[k][start] = (int)(start == n);
            return (int)(start == n);
        }


        if(start == n){
            cout << k << "\n";
            dp[k][start] = (int)(k == 0);

            return (int)(k == 0);
        }

        if(start < n && !isPrime(s[start])){
            dp[k][start] = 0;
            return 0;
        }

        if(start + minLength*k > n)
        return 0;

        int res = 0;

        for(int j = start+1; j < n; ++j){
            if(j == n-1){
                if(!isPrime(s[j]) && j-start+1 >= minLength){
                    res += helper(s, k-1, minLength, j+1, dp)%mod;
                    res %= mod;
                }
            }
            else{
                if(!isPrime(s[j]) && isPrime(s[j+1]) && j-start+1 >= minLength){
                    res += helper(s, k-1, minLength, j+1, dp)%mod;
                    res %= mod;
                }
            }
        }

        res %= mod;
        dp[k][start] = (int)res;
        return (int)(res);

    }


    int beautifulPartitions(string s, int k, int minLength) {
        int n = s.length();

        //cout << isPrime(s[0]);

        if(!isPrime(s[0]) || isPrime(s[n-1]))
        return 0;


        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        //cout << "hello";

        int ans = helper(s, k, minLength, 0, dp);
        return ans;

    }
};
