#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    unordered_map<int, int> m;
    
    int get(int x){
    
        for(int num = -50; num < 0; ++num){
            if(m.find(num) != m.end()) x -= m[num];
            if(x <= 0) return num;
        }
    
        return 0;
    }
    
    vector<int> getSubarrayBeauty(vector<int>& v, int k, int x) {
        
        int n = v.size();

        
        vector<int> beauty;
        for(int i = 0; i < k; ++i) if(v[i] < 0) m[v[i]]++;
        int j = k;
        

        while(j <= n){
            
            beauty.push_back(get(x));
            if(j == n) break;
            
            int rem = v[j-k];
            if(rem < 0){
                m[rem]--;
                if(m[rem] == 0) m.erase(rem);
            }

            if(v[j] < 0) m[v[j]]++;
            ++j;
            
            continue;
        }
        
        
        return beauty;
    }
};
