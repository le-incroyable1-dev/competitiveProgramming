#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& f) {

        int n = f.size();

        int count = 0;
        int ans = INT_MIN;
        int start = 0;
        unordered_map<int, int> m;

        for(int i = 0; i < n; ++i){
            if(m.find(f[i]) == m.end()){
                if(m.size() == 2){
                    ans = max(ans, count);
                    //count = 1;

                    while(m.size() == 2){
                        m[f[start]]--;
                        count--;

                        if(m[f[start]] == 0) m.erase(f[start]);
                        start++;
                    }

                    m[f[i]]++;
                    count++;
                    ans = max(ans, count);
                }
                else{
                    m[f[i]]++;
                    count++;
                    ans = max(ans, count);
                }
            }
            else{
                ++count;
                m[f[i]]++;
                ans = max(ans, count);
            }
        }

        return ans;
    }
};
