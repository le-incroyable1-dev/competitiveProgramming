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
    int firstMissingPositive(vector<int>& v) {

        int n = v.size();

        for(int i = 0; i < n; ++i) if(v[i] <= 0) v[i] = n+1;

        for(int i = 0; i < n; ++i){

            int cur = abs(v[i]);
            if(cur <= n && v[cur-1] > 0) v[cur-1] *= -1; 
        }

        for(int i = 0; i < n; ++i) if(v[i] > 0) return i+1;
        return n + 1;
        
    }
};
