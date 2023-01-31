class Solution {
    
private:
    
    int find_set(int v, vector<int> &parent) {
        if(v == parent[v]) return v;
        else return find_set(parent[v], parent);
    }

    void union_sets(int a, int b, vector<int> &parent, vector<int> &rank) {
        a = find_set(a, parent);
        b = find_set(b, parent);
        if (a != b) {
            if (rank[a] < rank[b]){
                int temp = a;
                a = b;
                b = temp;
            }
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
    
    
public:
    int minimumHammingDistance(vector<int>& s, vector<int>& t, vector<vector<int>>& v) {
        
        
        int n = s.size();
        
        vector<int> uf(n, -1);
        for(int i = 0; i < n; ++i)
            uf[i] = i;
        
        vector<int> rank(n, 1);
        
        for(auto val : v){
            
            int v1 = find_set(val[0], uf);
            int v2 = find_set(val[1], uf);
            
            union_sets(v1, v2, uf, rank);
        }
        
        unordered_map<int, multiset<int>> m;
        
        for(int i = 0; i  < n; ++i){
            
            m[t[i]].insert(i);
        }
        
        int ans = n;
        
        for(int i = 0; i < n; ++i){
            int a = find_set(i, uf);
            int b = -1;
            
            for(auto num : m[s[i]]){
                b = find_set(num, uf);
                
                if(a == b){
                    ans--;
                    m[s[i]].erase(num);
                    break;
                }
            }
        }
        
        return ans;
    }
};
