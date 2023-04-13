#include <bits/stdc++.h>
using namespace std;

static auto _______ = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

        stack<int> s;

        int n = pushed.size();
        int i = 0;
        int j = 0;

        while(1){
            int po = popped[j];

            while(s.empty() || s.top() != po){
                if(i == n) return false;

                s.push(pushed[i]);
                ++i;
            }

            if(s.empty() || s.top() != po) return false;

            s.pop(); ++j;
            if(j == n) break; 
        }
        
        return true;
    }
};
