typedef long long ll;
#define mod 1000000007

class Solution {
public:
    int waysToSplit(vector<int>& v) {
        int n = v.size();
        
        vector<ll> pre(n, 0);
        ll sum = 0;
        
        for(int i = 0;i < n; ++i){
            sum += v[i];
            pre[i] = sum;
            
            //cout << sum << " ";
        }
        //cout << "\n";
        
        ll ans = 0;
        
        for(int l = 0; l < n; ++l){
            ll lsum = pre[l];
            
            ll req = sum-lsum;
            req /= 2;
            
            //cout << req << " ";
            
            ll cur = (ll)(upper_bound(pre.begin()+l+1, pre.end(), lsum+req) - lower_bound(pre.begin()+l+1, pre.end(), lsum+lsum));
            cur = max(cur, 0LL);

            
            
            //cout << cur << "\n";
            
            (ans += cur)%=mod;
        }
        
        return ans;
    }
};
