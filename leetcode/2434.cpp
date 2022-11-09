class Solution {
public:
    string robotWithString(string s) {
        
        string ans;
        string t;
        
        multiset<char> sc;
        multiset<char>::iterator itr;
        for(auto c : s)
            sc.insert(c);
        
        int n = s.length();
        
        
        for(int i = 0; i < n; ++i){

            while(!t.empty() && t.back() <= *sc.begin()){
                ans += t.back();
                t.pop_back();
                //sc.erase(sc.begin());
            }

            t += s[i];
            itr = sc.find(s[i]);
            
            if(itr != sc.end())
            sc.erase(itr);


            while(!t.empty() && t.back() <= *sc.begin()){
                ans += t.back();
                t.pop_back();
                //sc.erase(sc.begin());
            }
            
            
            
        }
        
        reverse(t.begin(), t.end());
        ans += t;
        
        return ans;
        
    }
};
