#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    long long countGood(vector<int>& v, int k) {
        
        ll ans = 0;
        int n = v.size();

        int i = 0;
        int j = 0;
        unordered_map<int, int> m;

        ll cur_pairs = 0;
        m[v[j]]++;

        while(i <= j && j < n){

            if(cur_pairs >= k){
                ans += n-j;
                m[v[i]]--;

                cur_pairs -= m[v[i]];
                ++i;
            }
            else{
                if(j == n-1) break;
                else{
                    ++j;
                    if(m[v[j]]) cur_pairs += m[v[j]];
                    m[v[j]]++;
                }
            }

            continue;

        }

        return ans;

    }
};
