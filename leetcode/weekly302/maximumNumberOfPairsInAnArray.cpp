
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> answer;
        int a1 = 0;
        int a2 = 0;
        
        int n = nums.size();
        unordered_map<int, int> m;
        
        for(int i = 0; i < n; ++i){
            if(m.find(nums[i]) == m.end())
                m.insert(make_pair(nums[i], 1));
            else{
                m.find(nums[i])->second++;
            }
        }
        
        unordered_map<int, int>::iterator itr;
        itr = m.begin();
        
        while(itr != m.end()){
            int count = itr->second;
            a1 += count/2;
            a2 += count%2;
            
            itr++;
        }
        
        answer.push_back(a1);
        answer.push_back(a2);
        
        return answer;
    }
};
