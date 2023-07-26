typedef long long ll;

class Solution {
public:
    
    vector<ll> mx;
    
    ll max_val(vector<int> &v, int i){
        
        int n = v.size();
        if(i >= n) return 0;
        ll val = v[i];
        if(i == n-1) return mx[i] = val;
        
        if(mx[i] != -1) return mx[i];
        
        ll nxt1 = max_val(v, i+1);
        ll nxt2 = max_val(v, i+2);
        val = max(val, nxt1);
        val = max(val, nxt2);

        
        if(v[i] <= nxt1) val = max(val, (ll)v[i] + nxt1);
        if(v[i] <= v[i+1]){ 
            val = max(val, (ll)v[i]+(ll)v[i+1]); 
            if(v[i] + v[i+1] <= nxt2) val = max(val, (ll)v[i] + (ll)v[i+1] + nxt2); 
        }
        
        return mx[i] = val;
    }
    
    long long maxArrayValue(vector<int>& v) {
        ll res = 0;
        int n = v.size();
        mx.resize(n+1, -1);
        
        res = max_val(v, 0);
        return res;
    }
};
