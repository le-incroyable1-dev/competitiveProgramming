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
    int numRescueBoats(vector<int>& p, int limit) {

        int n = p.size();
        int i = 0, j = n-1;
        sort(p.begin(), p.end());

        int boats = 0;
        while(i < j){
            int cur = p[i] + p[j];
            if(cur <= limit){
                p[i] = 0; p[j] = 0;
                ++boats;
                ++i;
                j--;
            }
            else j--;
        }

        for(auto val : p) if(val != 0) ++boats;
        return boats;

    }
};
