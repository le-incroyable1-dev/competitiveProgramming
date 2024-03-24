#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long p = 53;
const long long mod = 1e9 + 9;
// - hyphen
// _ underscore

class Solution {
public:
    vector<int> stringIndices(vector<string>& wc, vector<string>& wq) {
        unordered_map<ll, int> hash;
        int n = wc.size();
        for(int x = 0; x < n; ++x){
            string q = wc[x];
            int m = q.length();

            ll hashval = 0; //empty suffix
            ll r = 1;

            for( int i = m - 1; ; i--){

                if(hash.find(hashval) == hash.end()) hash[hashval] = x;
                else if(wc[hash[hashval]].length() > m) hash[hashval] = x;

                if(i < 0) break;

                hashval = (hashval + 1LL * (q[i] - 'a' + 1) * r)%mod;
                r = (r * p)%mod;
            }
        }

        vector<int> ans;

        for(auto s : wq){
            int res = 0;

            int m = s.length();
            ll hashval = 0;
            ll r = 1;

            for( int i = m - 1; ; i--){
                
                if(hash.find(hashval) != hash.end()) res = hash[hashval];

                if(i < 0) break;

                hashval = (hashval + 1LL * (s[i] - 'a' + 1) * r) % mod;
                r = (r * p)%mod;
            }

            ans.push_back(res);
        }

        return ans;
    }
};
