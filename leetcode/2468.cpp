#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int sz(int a){
        string s = to_string(a);
        return (int)s.length();
    }
    
    vector<string> splitMessage(string m, int lim) {
        vector<string> ans;
        int n = m.length();
        int indices_len = 1;
        int parts = 1;
        
        while(indices_len + 3*parts + n + parts*sz(parts) > parts*lim){
            if(3 + 2*sz(parts) > lim) return {};
            ++parts;
            indices_len += sz(parts);
        }
        
        int cur = 1;
        int j = 0;
        
        //cout << parts << "\n";
        
        while(cur <= parts){
            int p_len = lim - sz(parts) - sz(cur) - 3;
            string m_p = m.substr(j, min(p_len, n - j));
            j += p_len;
            string s = m_p + "<" + to_string(cur) + "/" + to_string(parts) + ">";
            //cout << s << "\n";
            ++cur;
            ans.push_back(s);
        }
        
        return ans;
    }
};
