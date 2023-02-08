#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    vector<int> ans;
    int res = INT_MIN;

public:

    void helper(int k, vector<int> &a, vector<int> &cur, int sum, int i, int n){

        if(i == n){
            if(sum > res){

                cur[0] += k;
                res = sum;
                ans = cur;
                cur[0] -= k;
            }

            return;
        }

        if(k > a[i]) {
            cur.push_back(a[i]+1);
            helper(k-a[i]-1, a, cur, sum+i, i+1, n);
            cur.pop_back();
        }

        cur.push_back(0);
        helper(k, a, cur, sum, i+1, n);
        cur.pop_back();

        return;

    }

    

    vector<int> maximumBobPoints(int k, vector<int>& a) {
        int n = a.size();
        vector<int> cur;
        helper(k, a, cur, 0, 0, n);

        return ans;
    }
};
