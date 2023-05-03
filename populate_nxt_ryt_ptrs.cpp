#include <bits/stdc++.h>
using namespace std;
#define tn TreeLinkNode *
 
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect (tn A) {

    tn s = A;
    tn pre = NULL;
    tn l_pre = s;

    while(1){

        tn nl_pre = NULL;
        pre = NULL;
        // cout << l_pre->val << " ";
        while(l_pre){
            
        
            if(l_pre->left){
                if(pre == NULL) pre = l_pre->left;
                else pre->next = l_pre->left, pre = pre->next;

                if(!nl_pre) nl_pre = l_pre->left;
            }

            if(l_pre->right){
                if(pre == NULL) pre = l_pre->right;
                else pre->next = l_pre->right, pre = pre->next;

                if(!nl_pre) nl_pre = l_pre->right;
            }

            l_pre = l_pre->next;
        }
        
        // if(nl_pre) cout << nl_pre->val << " ";
        // else cout << "NULL ";
        
        l_pre = nl_pre;
        // cout << "\n";
        if(l_pre == NULL) return;
    }
    
    // cout << "\n\n";

    return;
}
