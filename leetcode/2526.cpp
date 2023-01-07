#include <bits/stdc++.h>
using namespace std;

class DataStream {
    
private:
    
    int value, k;
    int counter;
    
public:
    
    
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        this->counter = 0;
    }
    
    bool consec(int num) {
        if(num == value){
            counter++;
        }
        else{
            counter = 0;
        }
        
        if(counter >= k)
            return true;
        
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
