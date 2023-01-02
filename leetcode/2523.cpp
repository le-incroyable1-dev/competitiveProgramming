#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000000

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
      
        //eratosthenes sir opp
        vector<bool> sieve(N+1, true);

        sieve[0] = false;
        sieve[1] = false;

        for(int i = 2; i <= N; ++i){
            if(sieve[i]){
                for(int j = 2*i; j <= N; j += i){
                    sieve[j] = false;
                }
            }
        }
      
        //////////////////////

        int spi = -1;
        for(int i = left; i <= right; ++i){
            if(sieve[i]){
                spi = i;
                break;
            }
        }

        if(spi == -1)
        return {-1, -1};

        int num1, num2;
        num1 = spi;
        num2 = -1;

        int n1, n2;
        n1 = -1;
        n2 = -1;

        int min_dif = INT_MAX;

        for(int i = spi+1; i <= right; ++i){
            if(sieve[i]){
                num2 = i;

                if(num2 - num1 < 3)
                return {num1, num2};

                if(num2 - num1 < min_dif){
                    min_dif = num2 - num1;
                    n2 = num2;
                    n1 = num1;
                }
                
                num1 = i;
                num2 = -1;
            }
        }

        if(min_dif == INT_MAX)
        return {-1, -1};
        else
        return {n1, n2};
    }
};
