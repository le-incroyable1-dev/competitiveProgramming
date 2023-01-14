#include <bits/stdc++.h>
using namespace std;



class Solution {

    char find(char x, vector<char> &dsu){
        int index = x-'a';

        if(dsu[index] == index+'a')
        return dsu[index];

        return find(dsu[index], dsu);
    }

public:
    string smallestEquivalentString(string s1, string s2, string b) {
        
        int n = b.length();
        int m = s1.length();

        vector<char> dsu(26, 0);
        for(int i = 0; i < 26; ++i){
            dsu[i] = (char)('a' + i);
        }

        for(int i = 0; i < m; ++i){

            char ch1 = find(s1[i], dsu);
            char ch2 = find(s2[i], dsu);

            char c1 = max(ch1, ch2);
            char c2 = min(ch1, ch2);

            if(c1 == c2)
            continue;

            dsu[c1-'a'] = min(dsu[c1-'a'], c2);
        }

        string ans = "";

        for(int i = 0;i < n; ++i)
        ans += find(b[i], dsu);
       

        return ans;
    }
};
