#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        int n = points.size();

        for(auto &v : points){
            int x = v[0];
            v[0] = v[1];
            v[1] = x;

            
        }

        sort(points.begin(), points.end());

        // for(auto v : points)
        // cout << v[0] << "-" << v[1] << "  ";

        int count = 1;
        int i = 0;
        int end = points[0][0];

        while(i < n){
            if(points[i][1] > end){
                ++count;
                end = points[i][0];
            }

            ++i;
        }

        return count;
        
    }
};
