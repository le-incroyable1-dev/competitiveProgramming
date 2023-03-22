#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int getCount(vector<int> &v, int num){
        int count = 0;
        for(auto val : v) if(val <= num) ++count;

        return count;
    }

    int findDuplicate(vector<int>& v) {

        int r = v.size()-1;
        int l = 1;

        int dup;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(getCount(v, mid) > mid)
            dup = mid, r = mid - 1;
            else
            l = mid + 1;
        }

        return dup;

    }
};
