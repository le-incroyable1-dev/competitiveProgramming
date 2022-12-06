#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:

    int countSubarrays(vector<int>& nums, int k) {

        unordered_map<ll, ll> ml;
        //unordered_map<ll, ll> mr;

        int n = nums.size();

        int ki = -1;
        for(int i = 0; i < n; ++i){
            if(nums[i] == k){
                ki = i;
                break;
            }
        }     
        
        ll s = 0;
        ll g = 0;
        ll ans = 0;

        vector<ll> v(n, -1);
        v[ki] = 0;
        ml[0]++;

        cout << ki << "\n";

        for(int i = ki-1; i >= 0; --i){
            if(nums[i] > k)
            g++;
            else
            s++;

            v[i] = g-s;
            cout << v[i] << "\n";
            ml[v[i]]++;
        }

        cout << "\n";

        g = 0;
        s = 0;

        for(int i = ki; i < n; ++i){
            if(nums[i] > k)
            g++;
            else if(nums[i] < k)
            s++;

            v[i] = g-s;
            cout << v[i] << "\n";

            if(ml[s-g])
            ans += ml[s-g];
            if(ml[1+s-g])
            ans += ml[1+s-g];
        }

        return (int)ans;

    }
};
