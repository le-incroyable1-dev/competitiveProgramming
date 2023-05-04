//author : aurav
//https://www.interviewbit.com/problems/order-of-people-heights/
//O(nlogn) solution using segment tree

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> seg;

void buildSeg(int i, int l, int r){

    if(l == r){
        seg[i] = 1; return;
    }

    int mid = l + (r-l)/2;
    buildSeg(2*i, l, mid);
    buildSeg(2*i+1, mid+1, r);

    seg[i] = seg[2*i] + seg[2*i +1];
    return;
}

void updateSeg(int i, int l, int r, int pos){

    if(pos < l || pos > r) return;
    if(l == r && l == pos){
        seg[i] = 0; return;
    }
    

    int mid = l + (r-l)/2;
    updateSeg(2*i, l, mid, pos);
    updateSeg(2*i+1, mid+1, r, pos);

    seg[i] = seg[2*i] + seg[2*i +1];
    return;
}


int querySeg(int i, int l, int r, int empty){

    if(seg[i] < empty) return -1;
    if(seg[i] == empty){

        if(l == r) return r;

        int mid = l + (r-l)/2;
        if(seg[2*i] == empty) return querySeg(2*i, l, mid, empty);
        else{
            int new_empty = empty - seg[2*i];
            if(seg[2*i+1] == new_empty) return querySeg(2*i+1, mid+1, r, new_empty);
        }
    }

    int mid = l + (r-l)/2;
    int le = querySeg(2*i, l, mid, empty);
    if(le != -1) return le;
    
    int new_empty = empty - seg[2*i];
    int re = querySeg(2*i+1, mid+1, r, new_empty);

    if(re != -1) return re;
    else return -1;
}


static bool cmp(vector<int> &v1, vector<int> &v2){ return v1[0] < v2[0]; }
vector<int> order(vector<int> &h, vector<int> &ifr) {

    int n = h.size();
    seg.resize(4*n+1, 1);
    buildSeg(1, 0, n-1);
    vector<int> res(n, 0);

    vector<vector<int>> v;
    for(int i = 0; i < n; ++i) v.push_back({h[i], ifr[i]});
    sort(v.begin(), v.end(), cmp);

    for(auto vec : v){
        int ht = vec[0];
        int fr = vec[1];
        ++fr;

        int pos = querySeg(1, 0, n-1, fr);
        if(pos == -1) return {};
        else{
            res[pos] = ht;
            updateSeg(1, 0, n-1, pos);
        }
    }

    return res;
}

int main(){
    vector<int> h = {5,3,2,6,1,4};
    vector<int> i = {0,1,2,0,3,2};

    order(h, i);
    return 0;
}
