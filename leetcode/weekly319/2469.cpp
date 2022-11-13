#include <bits/stdc++.h>

class Solution {
public:
    vector<double> convertTemperature(double c) {
        
        vector<double> v;
        double k,f;
        k = c + (double)273.15;
        f = (c*(double)1.80) + (double)32;
        
        
        k = round(k*100000.0)/100000.0;
        f = round(f*100000.0)/100000.0;
        
        v.push_back(k);
        v.push_back(f);
        
        return v;
    }
};
