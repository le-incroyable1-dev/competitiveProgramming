//author : aurav
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
vector<int> a;

int solve(int n, int s, int i){

    if(i<0 || s>n) return 699;

    if(s == n) return 0;

    int d = n-s, k = 0;
    for(int j=40;j>=0;j--){
        if((d>>j)&1==1) k++;
    }

    int res = k;
    res = min(res, solve(n, s, i-1));
    res = min(res, 1 + solve(n, s+a[i], i-1));

    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, i;
    int k = 1;
    i = 1;

    a.pb(1);
    while (1)
    {
        k *= i;
        if(k > 1e12) break;
        a.pb(k);
        i++;
    }
    i--;

    

    cin >> t;

    while (t--)
    {
        cin >> n;
        cout<<solve(n,0,a.size()-1)<<endl;
        
    }

    return 0;
}
