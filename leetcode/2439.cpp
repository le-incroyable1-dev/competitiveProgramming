#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static auto _______ = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
    
}();

class Solution {
public:
    int minimizeArrayValue(vector<int>& v) {

        int n = v.size();
        ll i = 0;
        ll sum = 0;

        int max_val = 0;

        while(i < n){
            sum += v[i];
            ll cur_best = (sum + i)/(i + 1);
            max_val = max(max_val, (int)cur_best);
            ++i;
        }

        return max_val;

    }
};
