class Solution {
public:
    int minimumDeviation(vector<int>& v) {

        set<int> s;

        int ans = INT_MAX;
       
        for(auto val : v){
            
            if(val%2 != 0) val *=2;
            s.insert(val);
            //cout << val << " ";
        }

        //cout << "\n";

        ans = min(ans,*s.rbegin() - *s.begin());

        while(*s.rbegin()%2 == 0){
            int cur = *s.rbegin();
            s.erase(cur);

            s.insert(cur/2);
            ans = min(ans, *s.rbegin() - *s.begin());
        }

        return ans;
        
    }
};
