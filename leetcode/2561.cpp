#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        ll ans = 0;

        sort(basket1.begin(), basket1.end());
        sort(basket2.begin(), basket2.end());

        for(auto v : basket1) cout << v << " ";
        cout << "\n";
        for(auto v : basket2) cout << v << " ";
        cout << "\n";


        map<int, ll> m;

        for(auto v : basket1) m[v]++;
        for(auto v : basket2) m[v]--;

        ll swaps = 0;

        for(auto [val, count] : m){
            if(count%2 != 0) return -1;
            swaps += max((ll)0, count/2);

            cout << val << " " << count << "\n";
        }

        //cout << swaps << "\n";

        ll small = m.begin()->first;

        for(auto [val, count] : m){
            int take = min(swaps, abs(count)/2);
            
            ans += (ll)take*min((ll)val, (ll)(small*2));
            swaps -= take;

            if(swaps == 0) break;
        }

        return ans;

    }
};
