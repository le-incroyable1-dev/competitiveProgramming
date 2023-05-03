#include <bits/stdc++.h>
using namespace std;
#define tn TreeNode*

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

unordered_map<tn, bool> m;
unordered_map<tn, tn> par;
tn bn = NULL;

void find(tn a, int b){
    queue<tn> q;
    q.push(a);
    
    while(!q.empty()){
        int sz = q.size();
        
        while(sz--){
            tn t = q.front(); q.pop();
            //m[t] = false;
            if(t->val == b){
                tn x = t;
                //cout << "found" << "\n";
                bn = x;
                //cout << bn->val << "\n";
            }
            
            if(t->left != NULL) q.push(t->left), par[t->left] = t;
            if(t->right != NULL) q.push(t->right), par[t->right] = t;
        }
    }
    
    return;
}

int ans = 0;

void burn(tn bn, int t){
    if(bn == NULL) return;
    //if(m.find(bn) != m.end() && m[bn] == true) return;
    ans = max(ans, t);

    m[bn] = true;

    if(par.find(bn) != par.end() && m[par[bn]] == false) burn(par[bn], t+1);
    if(bn->left && m[bn->left] == false) burn(bn->left, t+1);
    if(bn->right && m[bn->right] == false) burn(bn->right, t+1);

    return;
}

int solve(TreeNode* a, int b) {
    bn = NULL;
    find(a, b);
    ans = 0;
    if(bn == NULL) return INT_MAX;
    //else cout << bn->val << "\n";
    burn(bn, 0);
    cout << std::flush;
    m.clear(); par.clear();
    bn = NULL;
    return ans;
}
