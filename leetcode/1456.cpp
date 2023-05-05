#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool v(char c){ return (c=='a' || c=='e' || c == 'i' || c == 'o' || c == 'u'); }

    int maxVowels(string s, int k) {
        int ct = 0;
        int ans = 0;

        int n = s.length();
        int i = 0;

        while(i < k){
             if(v(s[i])) ++ct;
             ++i;
        }

        ans = max(ans, ct);
        while(i < n){
            //cout << ct << "\n";
            ans = max(ans, ct);
            if(v(s[i-k])) ct--;
            if(v(s[i])) ct++;

            ++i;
        }
        ans = max(ans, ct);

        return ans;
    }
};
