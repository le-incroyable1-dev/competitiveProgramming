#include <bits/stdc++.h>
using namespace std;


/*

In any station between A and B, let's say C. C will have gas left in our tank, if we go from A to that station. 
We can't reach B from A with some gas(may be 0) left in the tank in C, so we can't reach B from C with an empty tank.


If the gas is more than the cost in total, there must be some stations we have enough gas to go through them. 
Let's say they are green stations. So the other stations are red. The adjacent stations with same color can be 
joined together as one. Then there must be a red station that can be joined into a precedent green station unless 
there isn't any red station, because the total gas is more than the total cost. In other words, all of the stations 
will join into a green station at last.

*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n  = gas.size();

        int total = 0;
        int cur = 0;
        int start = 0;

        for(int i = 0; i < n; ++i){
            cur += gas[i]-cost[i];
            total += gas[i]-cost[i];

            if(cur < 0){
                cur = 0;
                start = i+1;
            }
        }

        if(total < 0)
        return -1;
        else
        return start;
    }
};

