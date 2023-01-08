#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        int res = INT_MIN;
        sort(p.begin(), p.end());
        int n = p.size();

        if(n == 1)
        return 1;

        vector<unordered_map<ld, int>> vm(n);

        for(int cur = 0; cur < n; ++cur){
            for(int next = cur+1; next < n; ++next){
                ld x1 = p[cur][0];
                ld y1 = p[cur][1];
                ld x2 = p[next][0];
                ld y2 = p[next][1];

                ld slope;

                if(x2 != x1)
                slope = (y2-y1)/(x2-x1);
                else
                slope = 0.6969;
                //if slope is infinite just set it to 0.6969 opp

                vm[next][slope]++;

                res = max(res, vm[next][slope]);
            }
        }

        res += 1;
        return res;
    }
};
