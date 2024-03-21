using ll = long long;
class Solution {
public:

    bool pal(int num){
        string s = to_string(num);
        int i = 0; int j = s.length() - 1;

        while(i < j){
            if(s[i] != s[j]) return false;
            ++i; j--;
        }

        return true;
    }

    long long minimumCost(vector<int>& v) {
        ll res = LLONG_MAX; sort(v.begin(), v.end());
        int n = v.size();
        ll mid = (n %2 )?v[n/2]: (v[n/2] + v[n/2 - 1])/2;
       // cout << mid << "\n";

        ll lower = mid;
        while(!pal(lower)) lower--;

        ll cost = 0; for(auto x : v) cost += abs( x - lower );
        res = min(res, cost);

        ll upper = mid;
        while(!pal(upper)) ++upper;

        cost = 0; for(auto x : v) cost += abs( x - upper );
        res = min(res, cost);

        return res;
    }
};
