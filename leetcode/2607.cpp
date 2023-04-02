typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;

static auto _______ = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    long long makeSubKSumEqual(vector<int>& v, int k) {
        
        //vector<int> kv;
        
        ll ops = 0;
        //unordered_set<int> s;
        int n = v.size();
        
        for(int i = 0; i < k; ++i){
            vector<int> curv;

            int j = i;
            while(v[j] != 0){
                curv.push_back(v[j]);
               // s.insert(j);
                v[j] = 0;
                j += k;
                j %= n;
            }
            
            int sz = curv.size();

            if(sz == 0) continue;
            int med;
            sort(curv.begin(), curv.end());
            if(sz%2 != 0) med = curv[sz/2];
            else med = (curv[sz/2] + curv[(sz/2) - 1])/2;

            for(auto val : curv) ops += abs((ll)med - (ll)val);

            //cout << ops << "\n";
            curv.clear();

        }
        
        return ops;
    }
};
