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

    vector<ll> seg;

    void buildSeg(int i, int l, int r){
        if(l == r){
            seg[i] = 1LL; return;
        }

        int mid = l + (r-l)/2;
        buildSeg(2*i, l, mid);
        buildSeg(2*i + 1, mid+1, r);

        seg[i] = seg[2*i] + seg[2*i + 1];
        return;
    }

    void updateSeg(int i, int l, int r, int pos){
        if(pos < l || pos > r) return;
        if(l == r && pos == l){
            seg[i] = 0LL; return;
        }

        int mid = l + (r-l)/2;
        updateSeg(2*i, l, mid, pos);
        updateSeg(2*i + 1, mid+1, r, pos);

        seg[i] = seg[2*i] + seg[2*i + 1];
        return;
    }

    ll querySeg(int i, int l, int r, int s, int e){
        
        if(s > e) return 0LL;
        if(r < s || l > e) return 0LL;
        if(s <= l && r <= e) return seg[i];

        int mid = l + (r-l)/2;
        ll ls = querySeg(2*i, l, mid, s, e);
        ll rs = querySeg(2*i + 1, mid+1, r, s, e);

        ll q = ls + rs;
        return q;
    }

    static bool cmp(pair<int, int> &p1, pair<int, int> &p2){
        return p1.first < p2.first;
    }

    long long countOperationsToEmptyArray(vector<int>& v) {

        ll ops = 0;
        int n = v.size();
        seg.resize(4*n+1, 0);
        buildSeg(1, 0, n-1);

        vector<pair<int, int>> vp;
        for(int i = 0; i < n; ++i) vp.emplace_back(v[i], i);
        sort(vp.begin(), vp.end(), cmp);

        int pre = -1;
        int i = 0;

        while(i < n){
            int val = vp[i].first;
            int j = vp[i].second;

            if(j > pre){
                ops += querySeg(1, 0, n-1, pre+1, j);
            }
            else{
                ops += querySeg(1, 0, n-1, 0, j);
                ops += querySeg(1, 0, n-1, pre+1, n-1);
            }

            updateSeg(1, 0, n-1, j);
            ++i;
            pre = j;
        }

        return ops;
    }
};
