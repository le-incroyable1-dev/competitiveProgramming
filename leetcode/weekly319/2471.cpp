/*
There is a limit to power and ability 
    but not to hope and belief!
---------------------------------------

  Author : Aurav S Tomar
*/


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
//#define tn TreeNode*
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};



  // struct TreeNode {
  //     int val;
  //     TreeNode *left;
  //     TreeNode *right;
  //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
  //     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  //     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  // };
 


class Solution {
public:

    int opscalc(vector<int> &v){

        int ops = 0;

        int n = v.size();
        unordered_map<int, int> m;

        fr(i, n)
        m[v[i]] = i;


        vector<int> sv = v;
        sort(all(sv));


        fr(i, n){
            if(sv[i] != v[i]){
                int cur = v[i];
                int index = m[sv[i]];

                v[i] = v[index];
                v[index] = cur;
                ops++;

                m[cur] = index;
                m[sv[i]] = i;
            }
        }

        return ops;
    }

    int minimumOperations(TreeNode* root) {
        
        queue<TreeNode*> q;

        q.push(root);
        q.push(NULL);

        int ops = 0;
        //unordered_map<int, int> m;
        vector<int> v;
        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();

            

            if(cur == NULL){
                ops += opscalc(v);
                v.clear();
                
                if(q.size() != 0)
                q.push(NULL);
                //m.clear();
                continue;
            }
            else{

                v.pb(cur->val);

                if(cur->left != NULL)
                q.push(cur->left);

                if(cur->right != NULL)
                q.push(cur->right);
                
                

                
            }
            
        }

        return ops;
        

    }
};


