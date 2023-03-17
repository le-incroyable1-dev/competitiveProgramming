#include <bits/stdc++.h>
using namespace std;

int Solution::mice(vector<int> &mice, vector<int> &holes) {
    
    sort(mice.begin(), mice.end());
    sort(holes.begin(), holes.end());
    int n = mice.size();
    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans = max(ans, abs(mice[i]-holes[i]));
    }
    
    return ans;
}
