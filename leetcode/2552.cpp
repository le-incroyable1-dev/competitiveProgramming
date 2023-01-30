#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    
    long long countQuadruplets(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> lv(n, vector<int>(n, 0));
        vector<vector<int>> rv(n, vector<int>(n, 0));

        for(int i = 0; i < n; ++i){
            int cur = nums[i];

            int count = 0;

            for(int j = i+1; j < n; ++j){
                if(nums[j] > cur)
                count++;

                rv[i][j] = count;
            }

            count = 0;

            for(int j = i-1; j >= 0; j--){
                if(nums[j] < cur)
                count++;

                lv[i][j] = count;
            }

        }

        ll ans = 0;

        for(int j = 0; j < n; ++j){
            for(int k = j+1; k < n; ++k){

                if(nums[j] <= nums[k]) continue;

                ll left = 0;
                ll right = 0;

                ll cur = 0;

                left = (ll)lv[k][0]-(ll)lv[k][j];
                right = (ll)rv[j][n-1]-(ll)rv[j][k];

                cur = left*right;
                ans += cur;
            }
        }

        return ans;
        
    }
};
