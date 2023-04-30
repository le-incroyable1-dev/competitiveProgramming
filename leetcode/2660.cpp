class Solution {
public:
    int isWinner(vector<int>& p1, vector<int>& p2) {
        
        int n = p1.size();
        int s1 = 0;
        int s2 = 0;
        
        s1 += p1[0];
        for(int i = 1; i < n; ++i){
            int s = 0;
            if(i == 1){
                s = p1[i];
                if(p1[i-1] == 10) s*=2;
            }
            else{
                s = p1[i];
                if(p1[i-1] == 10 || p1[i-2] == 10) s*=2;
            }
            
            s1 += s;
        }
        
        s2 += p2[0];
        for(int i = 1; i < n; ++i){
            int s = 0;
            if(i == 1){
                s = p2[i];
                if(p2[i-1] == 10) s*=2;
            }
            else{
                s = p2[i];
                if(p2[i-1] == 10 || p2[i-2] == 10) s*=2;
            }
            
            s2 += s;
        }
        
        if(s1 > s2) return 1;
        else if(s1 == s2) return 0;
        else return 2;
        
    }
};
