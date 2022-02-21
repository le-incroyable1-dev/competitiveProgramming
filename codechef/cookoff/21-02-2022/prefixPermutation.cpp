#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

void solve(int n, int k, vector<int> v){
    
    vector<int> res;
    
    for(int i = 0; i < n; i++)
    res.push_back(i+1);
    
    int i1 = 0;
    int i2 = 0;
    
    reverse(res.begin(), res.begin()+v.at(0));
    
    for(int i = 0; i < k-1 ; i++){
        i1 = v.at(i);
        i2 = v.at(i+1);
        
        reverse(res.begin()+i1, res.begin()+i2);
    }

    
    for(auto val : res)
    cout << val << " ";
    
}

int main() {
    
    int t = 0; 
    cin >> t;
    
    while(t--){
        
        int n;
        int k;
        vector<int> v;
        int ai;
        
        cin >> n >> k;
        
        for(int i = 0; i < k; i++){
            cin >> ai;
            v.push_back(ai);
        }
        
        sort(v.begin(), v.end());
        
        solve(n, k, v);
        cout << endl;
        
    }
    
	// your code goes here
	return 0;
}
