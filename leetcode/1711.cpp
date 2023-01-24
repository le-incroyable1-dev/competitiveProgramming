#define mod 1000000007
typedef long long ll;

class Solution {
public:
    int countPairs(vector<int>& d) {
        
        unordered_map<ll, ll> m;
        
        
        int n = d.size();
        
        cout << n << "\n";
        
        ll ans = 0;
        for(int i = 0; i < n; ++i){
        
            
            //cout << d[i] << "\n";
            
            for(int p = 0; p <= 40; ++p){
                ll cp = pow(2, p);
                ll req = cp-(ll)d[i];
                
                if(m[req])
                ans += m[req];
                
                ans%=mod;
            }
            
            //cout << ans << "\n";
            
            m[d[i]]++;
        }
        
        return (int)ans;
    }
};
