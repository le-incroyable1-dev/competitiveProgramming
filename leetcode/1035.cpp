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
    vector<vector<int>> lines;
    unordered_map<int, vector<int>> m1;
    unordered_map<int, vector<int>> m2;
    
    int count(vector<int> &v1, vector<int> &v2, int i, int j){
        
        int n = v1.size();
        int m = v2.size();
        int res = 0;
        
        
        if(i >= n || j >= m) return lines[i][j] = 0;
        if(lines[i][j] != -1) return lines[i][j];
        
        if(v1[i] == v2[j]){ 
            res++; 
            res += count(v1, v2, i+1, j+1); 
        }
        else{
            
            int c1 = 0;
            int e = v1[i];
            
            if(m2.find(e) != m2.end()){
                int x = lower_bound(m2[e].begin(), m2[e].end(), j+1) - m2[e].begin();
                if(x < m2[e].size()){
                    c1++;
                    int j1 = m2[e][x];
                    c1 += count(v1, v2, i+1, j1+1);
                }
            }
            
            int c2 = 0;
            e = v2[j];
            if(m1.find(e) != m1.end()){
                int x = lower_bound(m1[e].begin(), m1[e].end(), i+1) - m1[e].begin();
                if(x < m1[e].size()){
                    c2++;
                    int i1 = m1[e][x];
                    c2 += count(v1, v2, i1+1, j+1);
                }
            }
            
            res = max(c1, c2);
        }
        
        int c3 = count(v1, v2, i+1, j+1);
        res = max(res, c3);
        
        return lines[i][j] = res;
        
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        
        for(int i = 0; i < n; ++i) m1[nums1[i]].push_back(i);
        for(int i = 0; i < m; ++i) m2[nums2[i]].push_back(i);
        
        
        lines.resize(n+3, vector<int>(m+3, -1));
        int max_count = count(nums1, nums2, 0, 0);
        return max_count;
        
    }
};
