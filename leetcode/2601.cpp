#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool primeSubOperation(vector<int>& v) {
        vector<int> primes;
        int n = v.size();
        
        vector<bool> is_prime(1001, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= 1000; i++) {
            if (is_prime[i] && (long long)i * i <= 1000) {
                for (int j = i * i; j <= 1000; j += i)
                    is_prime[j] = false;
            }
        }
        
        
        for(int i = 0; i <= 1000; ++i) if(is_prime[i]) primes.push_back(i);
        int k = primes.size();
        
        
        for(int i = n-2; i >= 0; i--){
        
            if(v[i] >= v[i+1]){
                int d = v[i]-v[i+1];
                
                int pi = upper_bound(primes.begin(), primes.end(), d) - primes.begin();
            
                if(pi == k || primes[pi] >= v[i]) return false;
                
                v[i] -= primes[pi];
            }
        }
        
        return true;
        
    }
};
