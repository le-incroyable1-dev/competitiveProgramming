#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

class Solution {

private: 
    
public:


    unordered_map<int,int> getFactors(int x){
        unordered_map<int,int> freq;
        int f=2;
        while(x>1 && f*f<=x){
            while(x%f==0){
                freq[f]++;
                x/=f;
            }
            f++;
        }
        if(x!=1)    freq[x]=1;        // itself prime
        return freq;
    }

    int findValidSplit(vector<int>& v) {
    
        int n = v.size();
        unordered_map<int, int> tot, cur;
        for(auto val : v){
            for(auto [f, c] : getFactors(val))
            ++tot[f];
        }

        int same = 0;
        for(int si = 0; si < n-1; ++si){
            for(auto [f, c] : getFactors(v[si])){
                
                //if found a new prime at si increment number of same primes
                if(cur.find(f) == cur.end()) cur[f]++, same++;
                else cur[f]++;
                
                //set same to zero again if all of f have been covered
                same -= (cur[f] == tot[f]);
            }
            
            //if there was no increment in same that means all of f for each f are covered till si, so it is a valid split
            if(same == 0) return si;
        }

        return -1;
    }
};
