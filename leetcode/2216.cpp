class Solution {
public:
    int minDeletion(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;
        
        int index = 0;
        
        for(int i = 0; i < n-1; ++i){
            
            if(index%2 == 0){
                while(i < n-1 && nums[i] == nums[i+1]){
                    //cout << i << "\n";
                    ++i;
                    ++ans;
                }
            }
            
            ++index;
            
        }
        
        //cout << ans << "\n";
        
        if((n-ans)%2 != 0) ++ans;
        return ans;
        
    }
};
