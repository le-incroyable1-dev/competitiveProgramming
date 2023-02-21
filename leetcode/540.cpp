#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 1) return nums[0];

        int l = 0;
        int r = n-1;

        int ans = -1;

        while(l <= r){
            int mid = l + (r-l)/2;

            //cout << mid << "\n";

            int fi, si;

            if(mid == n-1){
                if(nums[mid] != nums[mid-1]) return nums[mid];
                r = mid-2;
                
            }
            else if(mid == 0){
                if(nums[mid] != nums[mid+1]) return nums[mid];
                l = mid+2;
            }
            else{
                if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];

                if(nums[mid] == nums[mid-1]){
                    fi = mid-1;
                    si = mid;
                }
                else{
                    fi = mid;
                    si = mid+1;
                }

                //cout << fi << " " << si << "\n";

                if(fi%2 == 0){
                    l = si+1;
                }
                else{
                    r = fi-1;
                }
            }


        }

        return ans;

    }
};
