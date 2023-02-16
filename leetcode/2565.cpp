#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumScore(string s, string t) {
        
        
        int n = s.length();
        int m = t.length();

        vector<int> lv(m, -1);
        vector<int> rv(m, -1);

        int i = 0;
        int j = 0;

        i = n-1;
        j = m-1;

        while(i >= 0 && j >= 0){
            if(s[i] == t[j]){
                rv[j] = i;
                j--; i--; 
            }
            else{
                i--;
            }
        }

        // for(auto v : lv) cout << v << " ";
        // cout << "\n";
        // for(auto v : rv) cout << v << " ";
        // cout << "\n";



        int l = n-1;
        int r = 0;

        int ans = j+1;
        i = 0;
        j = 0;
        
        int match = 0;

        while(i < n && j < m){
            if(s[i] == t[j]){
                while(match < m && rv[match] <= i) ++match;

                //cout << i << " " << j << " " << match << "\n";

                if(match > j)
                ans = min(ans, match-j-1);
                ++j;
            }
            
            ++i;
        }
        //cout << r  << " " << l << "\n";

        
        return ans;
    }
};
