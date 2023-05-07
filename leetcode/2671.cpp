#include <bits/stdc++.h>
using namespace std;

class FrequencyTracker {
public:
    
    unordered_map<int, int> m;
    unordered_map<int, int> f;
    
    FrequencyTracker() {}
    
    void add(int number) {
        if(m.find(number) == m.end()){
            m[number]++;
            f[1]++;
        }
        else{
            int cur_f = m[number];
            m[number]++;
            f[cur_f]--;
            f[cur_f+1]++;
        }
        
        return;
    }
    
    void deleteOne(int number) {
        if(m.find(number) != m.end()){
            if(m[number] == 0) return;
            
            int cur_f = m[number];
            m[number]--;
            f[cur_f]--;
            f[cur_f-1]++;
        }
        
        return;
    }
    
    bool hasFrequency(int frequency) {
        if(f.find(frequency) != f.end()){
            return (f[frequency] > 0); 
        }
        
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
