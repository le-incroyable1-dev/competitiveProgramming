#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool valid(int &i, string &s){
        return (i < 1 || s[i] != s[i - 1]) && (i < 2 || s[i] != s[i - 2]);
    }

    string smallestBeautifulString(string s, int k) {
        
        int n = s.length();

        int i = n-1;

        while(i >= 0){
            ++s[i];
            while(!valid(i, s)) ++s[i];

            if(s[i] < 'a' + k){
                //bool canRet = true;
                for(i = i+1; i < n; ++i){
                    s[i] = 'a';
                    while(!valid(i, s)) ++s[i];
                }
                return s;
            }

            i--;
        }

        return "";
    }
};
