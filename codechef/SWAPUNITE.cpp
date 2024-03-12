#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin >> t;
	while(t--){
	    string s; cin >> s;
	    int ans = 1e6; int n = s.length();
	    
	    vector<vector<int>> upto(n, vector<int>(26, 0));
	    upto[0][s[0] - 'a']++;
	    
	    
	    
	    for(int i = 1 ;i < n; ++i){
	        for(int c = 0; c < 26; ++c){
	            upto[i][c] = upto[i-1][c] + (s[i] == c + 'a');
	        }
	    }
	    
	    
	    
	    for(int i = 0 ; i < n; ++i){
	        for(int c = 0; c < 26; ++c){
	            int ccount = upto[n-1][c];
	            if(i + ccount > n || ccount == 0) continue;
	            
	            ans = min(ans, ccount - ( upto[i + ccount - 1][c] - upto[i][c] + (s[i] - 'a' == c)) );
	        }
	    }
	    
	    cout << ans << '\n';
	}

}
