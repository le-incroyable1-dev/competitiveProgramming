#include <bits/stdc++.h>
using namespace std;

int Solution::maxp3(vector<int> &v) {
    
    int n = v.size();
    sort(v.begin(), v.end());
    
    int ans = max(v[n-1]*v[n-2]*v[n-3], v[0]*v[1]*v[n-1]);
    return ans;
}
