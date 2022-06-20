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


//https://www.youtube.com/watch?v=YA-nB2wjVcI&t=725s

// morris traversal allows you to traverse the tree in constant space
// and O(n) time. neither recursion nor stack is required.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> morrisInorderTraversal(TreeNode* root) {
    TreeNode* curNode = root;
    vector<int> nodes;
    
    while (curNode != NULL) 
    {
        if (curNode -> left) 
        {
                        //Find the inorder predecessor of current
            //ifa) Make current as right child of the rightmost node in current's left subtree
            TreeNode* predecessor = curNode -> left;
            while (predecessor -> right && predecessor -> right != curNode) //second condition used when reverting
                predecessor = predecessor -> right;
            
            if ((predecessor -> right)==NULL) 
            {
                predecessor -> right = curNode;
                curNode = curNode -> left; //ifb) Go to this left child
            }
            else 
            {
                //Revert back the changes
                predecessor -> right = NULL;
                nodes.push_back(curNode -> val);
                curNode = curNode -> right;
            }
        }
        else 
        {
            nodes.push_back(curNode -> val);  //ea)
            curNode = curNode -> right;  //eb)
        }
    }
    
    return nodes;
  
  // neat
}
