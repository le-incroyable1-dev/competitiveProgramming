class Solution {
public:
    int minimumSum(int n, int k) {
        int num = 1;
        int count = 0;
        int sum = 0;
        unordered_set<int> s;
        
        while(num <= k && count < n){
            if(s.find(num) != s.end()){ ++num; continue; }
            //cout << num << " ";
            sum += num;
            s.insert(num);
            s.insert(k-num);
            ++count; ++num;
        }
        
        num = k+1;
        
        while(count < n) sum += num, ++count, ++num;
        return sum;
    }
};
