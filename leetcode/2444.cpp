#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    long long countSubarrays(vector<int>& v, int mink, int maxk) {
        
        long long ans = 0;
        int n = v.size();

        vector<int> lo(n, -1);
        vector<int> lf(n, -1);

        int oc = -1;
        int fc = -1;
        for(int i = 0; i < n; ++i){
            if(v[i] == mink) oc = i;
            if(v[i] == maxk) fc = i;

            lo[i] = oc;
            lf[i] = fc;
        }

        oc = -1;
        fc = -1;

        vector<int> luo(n, -1);
        vector<int> luf(n, -1);

        for(int i = 0; i < n; ++i){
            if(v[i] < mink) oc = -1;
            else if(oc == -1) oc = i;

            if(v[i] > maxk) fc = -1;
            else if(fc == -1) fc = i;

            luo[i] = oc;
            luf[i] = fc;
        }

        // for(auto val : lo) cout << val << " ";
        // cout << "\n";
        // for(auto val : lf) cout << val << " ";
        // cout << "\n";
        // for(auto val : luo) cout << val << " ";
        // cout << "\n";
        // for(auto val : luf) cout << val << " ";
        // cout << "\n";

        for(int i = 0; i < n; ++i){

            if(v[i] < mink || v[i] > maxk) continue;

            ll i1 = max(luo[i], luf[i]);
            ll i2 = min(lo[i], lf[i]);

            ans += max(0LL, i2-i1+1LL);

        }

        return ans;
        
        
    }
};
