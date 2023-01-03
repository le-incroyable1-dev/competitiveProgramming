#include <bits/stdc++.h>
using namespace std;
#define ll long long


class Solution {
public:

    bool check(vector<int> &price, int k, int mid){
        vector<int>::iterator it = price.begin();

        // the first element is already considered at price.begin()
        k -= 1;

        ll MX = 1e9;

        while(it != price.end() && k > 0){
            ll find = *it + mid;

            if(find > MX)
            it = price.end();
            else
            it = lower_bound(price.begin(), price.end(), find);

            if(it != price.end()){
                k--;
            }
        }

        if(k > 0)
        return false;
        else
        return true;
    }

    int maximumTastiness(vector<int>& price, int k) {

        int n = price.size();
        sort(price.begin(), price.end());

        

        int max_t = price[n-1] - price[0];
        int min_t = 0;

        

        int ans = INT_MIN;

        while(min_t <= max_t){
            int mid = min_t + (max_t - min_t)/2;

            cout << min_t << " " << max_t << " : " << mid << "\n";
            

            if(check(price, k, mid)){
                ans = max(ans, mid);
                min_t = mid + 1;
            }
            else
            max_t = mid - 1;

            cout << ans << "\n";
        }

        return ans;
    }
};
