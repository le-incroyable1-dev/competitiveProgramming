#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& v) {
        ll ans = 0;
        int n = v.size();

        int i = 0; int j = 0;

        while(i < n && j < n){
            while(i < n && v[i] != 0) ++i;
            j = i;

            while(j < n && v[j] == 0) ans += ((ll)j - (ll)i + 1LL), ++j;
            i = j;
            
            continue;
        }

        return ans;
    }
};
