#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isItPossible(string w1, string w2) {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        
        unordered_map<char, int>::iterator itr1, itr2;
        
        for(auto c : w1)
            m1[c]++;
        for(auto c : w2)
            m2[c]++;
        
        // int sel;
        // bool res = false;
        // unordered_map<char, int> m1 = mms1;
        // unordered_map<char, int> m2 = mms2;
        
        itr1 = m1.begin();
        while(itr1 != m1.end()){
            
            itr2 = m2.begin();
            while(itr2 != m2.end()){                    
                auto [c1, v1] = *itr1;
                auto [c2, v2] = *itr2;

                unordered_map<char, int> mn1 = m1;
                unordered_map<char, int> mn2 = m2;

                unordered_map<char,int>::iterator itrn1 = mn1.find(c1);
                unordered_map<char,int>::iterator itrn2 = mn2.find(c2);
                
                if(mn1[c1] <= 0 || mn2[c2] <= 0){
                    ++itr2;
                    continue;
                }

                mn1[c1]--;
                mn2[c1]++;
                if(mn1[c1] == 0)
                    mn1.erase(itrn1);

                mn2[c2]--;
                mn1[c2]++;

                if(mn2[c2] == 0)
                    mn2.erase(itrn2);

                if(mn1.size() == mn2.size()){
                    cout << c1 << " " << c2 << "\n";
                    return true;
                }
                
                mn1.clear();
                mn2.clear();

                ++itr2;
            }
            ++itr1;
        }
        
        m1.clear();
        m2.clear();
        return false;
    }
};
