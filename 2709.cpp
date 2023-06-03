#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    unordered_map<int, unordered_set<int>> p_m;
    vector<int> par;
    vector<int> rank;

    int find_set(int v) {
        if (v == par[v])
            return v;
        return par[v] = find_set(par[v]);
    }

    void make_set(int v) {
        par[v] = v;
        rank[v] = 0;
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            
            par[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }


    void primeFactors(int n, int &j)
    {
        // Print the number of 2s that divide n
        while (n % 2 == 0)
        {
            p_m[2].insert(j);
            n = n/2;
        }
    
        // n must be odd at this point. So we can skip
        // one element (Note i = i +2)
        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            // While i divides n, print i and divide n
            while (n % i == 0)
            {
                p_m[i].insert(j);
                n = n/i;
            }
        }
    
        // This condition is to handle the case when n
        // is a prime number greater than 2
        if (n > 2) p_m[n].insert(j);


    }
    
    
    bool canTraverseAllPairs(vector<int>& nums) {
     
        int n = nums.size();
        for(int i = 0; i < n; ++i) primeFactors(nums[i], i);   

        par.resize(n, 0);
        rank.resize(n, 0);

        for(int i = 0; i < n; ++i) make_set(i);

        for(int i = 0; i < 2; ++i){
                for(auto [i, v] : p_m){

                if(v.size() == 0) continue;

                int f_mem = *v.begin();
                for(auto mem : v) union_sets(f_mem, mem);

//                 for(auto val : par) cout << val << " ";
//                 cout << "\n";
            }
        }

        unordered_set<int> par_set;
        for(auto val : par) par_set.insert(val);

        if(par_set.size() == 1) return true;
        else return false;
    }
};

int main(){

    vector<int> v = {14,30,30,49};
    Solution sol;
    sol.canTraverseAllPairs(v);    
    return 0;
}
