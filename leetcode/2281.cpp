#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

class Solution {
public:
    int totalStrength(vector<int>& s) {
        
        int n = s.size();
        vector<ll> prefix(n, 0);
        vector<ll> pp(n, 0);

        prefix[0] = s[0]%mod;
        for(int i = 1; i < n; ++i) (prefix[i] = prefix[i-1] + s[i])%=mod;
        pp[0] = prefix[0]%mod;
        for(int i = 1; i < n; ++i) (pp[i] = pp[i-1] + prefix[i])%=mod;

        // for(auto v : prefix) cout << v << " ";
        // cout << "\n";
        // for(auto v : pp) cout << v << " ";
        // cout << "\n";

        //prefix.clear();

        vector<ll> rv(n, n);
        vector<ll> lv(n, -1);

        stack<int> st;

        for(int i = 0; i < n; ++i){
            while(!st.empty() && s[st.top()] >= s[i]) st.pop();
            if(!st.empty()) lv[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && s[st.top()] > s[i]) st.pop();
            if(!st.empty()) rv[i] = st.top();
            st.push(i);
        }

        // for(auto v : lv) cout << v << " ";
        // cout << "\n";
        // for(auto v : rv) cout << v << " ";
        // cout << "\n";
        
        ll ans = 0;

        for(int i = 0; i <n; ++i){
            ll l = lv[i]; ll r = rv[i];

            ll cur = 0;

            //cout << i << " " << l << " " << r << "\n";

            cur += ((i-l) * (pp[r-1] - pp[i] + prefix[i]+mod)%mod)%mod;
            cur%=mod;

            ll v1, v2, v3;

            if(i-1 < 0) v1 = 0;
            else v1 = pp[i-1];

            if(l < 0){
                v2 = 0;
                v3 = 0;
            }
            else{
                v2 = pp[l];
                v3 = prefix[l];
            }

            cur -= ((r-i) * (v1-v2+v3+mod)%mod)%mod;

            cur=(cur+mod)%mod;

            (cur *= s[i])%=mod;

            (ans += cur)%=mod;

            //cout << ans << "\n";
        }
        

        return ans%mod;
        
    }
};
