#include <bits/stdc++.h>
using namespace std;



int merging_inversions(vector<int> &v, int l, int m, int r){
    
    vector<int> left, right;
    
    for(int i = l; i <= m; ++i) left.push_back(v[i]);
    for(int i = m+1; i <= r; ++i) right.push_back(v[i]);
    
    int li = 0, ri = 0, ki = l;
    int swaps = 0;
    
    while(li < left.size() && ri < right.size()){
        if(left[li] <= right[ri]){
            v[ki++] = left[li++];
        }
        else{
            v[ki++] = right[ri++];
            swaps += (m+1)-(l+li);
        }
    }
    
    
    while(li < left.size()) v[ki++] = left[li++];
    while(ri < right.size()) v[ki++] = right[ri++];
    
    return swaps;
}

int inversions(vector<int> &v, int l, int r){
    
    if(l >= r) return 0;
    
    int res = 0;
    
    int m = l + (r-l)/2;
    res += inversions(v, l, m);
    res += inversions(v, m+1, r);
    res += merging_inversions(v, l, m, r);
    
    return res;
}


int Solution::countInversions(vector<int> &v) {
    
    int n = v.size();
    int ans = inversions(v, 0, n-1);
    return ans;
    
}
