#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
typedef long double  ld;
#define pii pair<ll,ll>
#define vi vector< ll >
#define vvi vector< vi >
#define vpi vector< pii >
#define vvpi vector< vpi >
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define test(t) ll t;cin>>t;while(t--)
#define mem(a,b) memset(a,b,sizeof(a))
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b)))
//#define ln ListNode*
//#define itr(type) type::iterator itr
//#define tn TreeNode*
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        vector<int> answer;

        ll n = nums.size();
        ll q = queries.size();
        ll sz = nums[0].length();

        fr(i, q){
            vector<int> query = queries[i];
            ll k = query[0];
            ll trim = query[1];
        
            vector<ll> cpy;
            unordered_map<ll, vector<ll>> m;
            
            fr(j, n){
                ll val = stoll(nums[j].substr(sz-trim));
                cpy.pb(val);

                if(m.find(val) == m.end()){
                    vector<ll> v;
                    v.pb(j);
                    m.insert(mp(val, v));
                }
                else
                    m.find(val)->second.pb(j);
                
            }

            sort(all(cpy));
            
            fr(i, n)
                cout << cpy[i] << " ";

            ll result = cpy[k-1];
            cout << endl << result << endl;
            ll index = -1;
            unordered_map<ll, vector<ll>>::iterator itr;
            itr = m.find(result);
            if(itr->second.size() > 1){
                ll size = itr->second.size();
                ll fo = itr->second.at(0);
                
                cout << "arr ";
                fr(i, size){
                    cout << itr->second.at(i) << " ";
                }
              
                
                cout << endl << k << " " << size << " " << fo << endl;

                if(k-1-fo >= 0 && k-1-fo < size)
                index = itr->second.at(k-1-fo);
                else
                index = itr->second.at(0);
            }
            else
            index = itr->second.at(0);

            //int index = m.find(result)->second.at(0);
            cpy.clear();
            answer.pb(index);
            
            cout << "end" << endl;
        }

        return answer;
    }
};
