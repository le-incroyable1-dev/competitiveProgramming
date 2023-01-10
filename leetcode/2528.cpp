#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100000


class Solution {
public:
  
    //sweep-line opp

    bool possible(vector<int> &s, int r, ll k, ll p){
        
        int n = s.size();
        ll cur_pow = 0;
        vector<ll> add(n, 0);

        for(int i = 0; i < r; ++i) cur_pow += s[i];

        for(int i = 0 ; i < n; ++i){

            if(i+r < n)
            cur_pow += s[i+r];

            if(cur_pow < p){
                ll req = p - cur_pow;

                if(req > k)
                return false;

                k -= req;
                add[min(n-1, i+r)] += req;

                cur_pow = p;
            }

            if(i-r >= 0){
                cur_pow -= s[i-r] + add[i-r];
            }
        }

        return true;

    }


    long long maxPower(vector<int>& s, int r, int k) {

        int n = s.size();

        if(n == 1)
        return (ll)s[0] + (ll)k;
        

        ll sum = 0;
        for(int i  = 0; i < n; ++i) sum += s[i];
        sum += k;

        ll min_pow = 0;
        ll max_pow = sum;
        ll res = INT_MIN;

        while(min_pow <= max_pow){
            ll mid_pow = min_pow + (max_pow - min_pow)/2;

            if(possible(s, r, k, mid_pow)){
                res = max(res, mid_pow);
                min_pow = mid_pow + 1;
            }
            else
            max_pow = mid_pow - 1;

        }

        return res;

    }
};
