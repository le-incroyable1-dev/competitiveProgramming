#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(arr) arr.begin(),arr.end()
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define per(i,a,b) for(ll i=a;i>=b;i--)

int Solution::solve(vector<vector<int> > &A) {

    ll n = A.size();
    ll m = A[0].size();

    vector<vector<int>> hts(n, vector<int>(m, 0));

    fr(i, n){
        fr(j, m){
            if(i == 0)
            hts[i][j] = A[i][j];
            else
            hts[i][j] = (A[i][j] == 1 ? 1 + hts[i-1][j] : 0);
        }
    }

    fr(i, n){
        sort(all(hts[i]));
        reverse(all(hts[i]));
    }

    int ans = 0;
    int base = 0;
    int ht = INT_MAX;
    

    fr(i, n){
        fr(j, m){
            if(hts[i][j] == 0){
                base = 0;
                ht = INT_MAX;
            }
            else{
                base++;
                ht = min(hts[i][j], ht);
                
                if(ht != INT_MAX)
                ans = max(ans, base*ht);
            }
        
        }
        
        base = 0;
        ht = INT_MAX;
    }

    return ans;

}
