#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        
       int n = lcp.size();
       vector<int> res(n, 0);

       int c = 1;
      
      //fill the string according to the information given in the lcp matrix
      //for any given position i, at each position j where lcp[i][j] > 0 then res[i] = res[j]
      //for the next i select the next smallest character

       for(int i = 0; i < n; ++i){
           if(res[i] > 0) continue;
           if(c > 26) return "";

           for(int j = i; j < n; ++j){
               if(lcp[i][j] > 0) res[j] = c;
           }

           ++c;

          
       }

       
    //    for(auto val : res) cout << val << " ";
    //    cout << "\n";
      
      //now check if the lcp condition satisfies for the constructed string res

       for(int i = 0; i < n; ++i){
           for(int j = 0; j < n; ++j){
               int value = 0;

               if(res[i] != res[j]) value = 0;
               else{
                   value = 1;
                   if(i+1 < n && j+1 < n) value += lcp[i+1][j+1];
               }

               if(lcp[i][j] != value) return "";
           }
       }
      
      //if it satisfied return the corresponding string form of res

       string s;
       for(auto val : res) s += (val + 'a' - 1);

       return s;
    }
};
