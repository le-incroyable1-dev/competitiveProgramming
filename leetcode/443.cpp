#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& v) {

        int n = v.size();
        int i = 0;
        int j = 0;

        char cur;
        int count = 0;

        while(i < n){
            cur = v[j];
            while(j < n && v[j] == cur) ++j, ++count;

            v[i] = cur;
            if(count > 1){
                ++i;
                string s = to_string(count);
                for(auto c : s){
                    v[i] = c;
                    ++i;
                }
            }
            else ++i;

            count = 0;
            if(j == n) break;
        }

        //for(auto c : v) cout << c << " ";
        int len = i;
        return len;

    }
};
