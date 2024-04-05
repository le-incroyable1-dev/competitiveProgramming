class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        multiset<long long>plus,minus;
        for(auto it:points){
            plus.insert(it[0]+it[1]);
            minus.insert(it[0]-it[1]);
        }
        long long maximum=LONG_MAX;
        for(int i=0;i<points.size();i++){
            
            int sum = points[i][0]+points[i][1];
            int diff = points[i][0]-points[i][1];
            plus.erase(plus.lower_bound(sum));
            minus.erase(minus.lower_bound(diff));
            
            maximum = min(maximum,max((*plus.rbegin()-*plus.begin()),(*minus.rbegin()-*minus.begin())));
            plus.insert(sum);
            minus.insert(diff);
        }
        return maximum;
    }
};
