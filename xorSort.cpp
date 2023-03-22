#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define tr(c,it) for(typeof(c.begin()) it=c.begin();it!=c.end();it++)
#define multi ll t;cin>>t;while(t--)
#define present(c,i) (c.find(i)!=c.end())
#define cpresent(c,i) (find(all(c),i)!=c.end())
#define mod 1000000007

void solve()
{
    ll n,i,j,k,u,v;
    cin>>n;
    vector<ll> a(n),b(n);
    for(i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b.begin(),b.end());
	unordered_map<ll,set<ll>> m;
	for(i=0;i<n;++i)
		m[a[i]].insert(i);

	vector<pair<ll,ll> > ans;
	for(i=0;i<n;++i)
	{
		j=*m[b[i]].begin();// position of actual value from sorted array in original array
		m[b[i]].erase(j);
    
		if(i==j) continue;
    
		ans.push_back({i,j});
		ans.push_back({j,i});
		ans.push_back({i,j});
    
    m[a[i]].erase(i);
		m[a[i]].insert(j);
    
		swap(a[i],a[j]);
		
	}
  
	cout<<ans.size()<<"\n";
	
  for(auto x:ans)
	{
        cout<<x.first<<" "<<x.second<<"\n";
	}
}


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
	cin>>t;
	while(t--)
    solve();
	return 0;
}
