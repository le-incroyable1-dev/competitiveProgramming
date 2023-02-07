#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCollisions(string d) {
        stack<char> s;
        
        int ans = 0;
        
        for(auto c : d){
            if(s.empty()) s.push(c);
            else{
                if(c == 'R'){
                    if(s.top() == 'L'){
                        s.push(c);
                    }
                    else if(s.top() == 'S'){
                        s.push(c);
                    }
                    else s.push(c);
                }
                else if(c == 'S'){
                    if(s.top() == 'L'){
                        s.push(c);
                    }
                    else if(s.top() == 'S'){
                        s.push(c);
                    }
                    else{
                        while(!s.empty() && s.top() == 'R'){
                            s.pop();
                            ans++;
                        }
                        
                        s.push('S');
                    }
                }
                else{
                    if(s.top() == 'L'){
                        s.push(c);
                    }
                    else if(s.top() == 'S'){
                        ans++;
                        s.pop();
                        
                        while(!s.empty() && s.top() == 'R'){
                            ans++;
                            s.pop();
                        }
                        
                        s.push('S');
                    }
                    else{
                        ans += 2;
                        s.pop();
                        
                        
                        while(!s.empty() && s.top() == 'R'){
                            ans++;
                            s.pop();
                        }
                        
                        s.push('S');
                    }
                }
            }
        }
        
        
        
        
     
        return ans;
    }
};
