#include <bits/stdc++.h>
using namespace std;


/*
1669E - 2-Letter Strings
One solution is to go through all given strings, generate all strings that differ in exactly one position, 
and count the number of times these strings occur in the array. A possible way to count them is by 
using either the map/dictionary data structure or even simpler — a frequency array. 
Depending on the implementation, you may need to divide the answer by 2 because of overcounting pairs.

The solution runs in O(nlogn) or O(n) depending on the implementation.

*/


int main() {

    int t; cin >> t;
    
    while(t--) {
        int n; cin >> n;

        vector<vector<int>> cnt(12, vector<int>(12, 0));
        long long ans = 0;
        
        for(int i = 0;i < n; ++i) {
            string s; cin >> s;
            for(int j = 0;j < 2; ++j) {
                for(char c = 'a'; c <= 'k'; ++c) {
                    if(c == s[j]) continue;
                    string a = s; a[j] = c;
                    ans += cnt[a[0] - 'a'][a[1] - 'a'];
                }
            }

            ++cnt[s[0] - 'a'][s[1] - 'a'];

        }

        cout << ans << "\n";
    }
}