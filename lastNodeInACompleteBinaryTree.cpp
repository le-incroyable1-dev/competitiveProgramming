#include <bits/stdc++.h>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
      TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//O(log(n).log(n)) == O(h^2)

int getHeight(TreeNode* root){
    
    int ht = 0;
    while(root != NULL) root = root->left, ++ht;

    return ht;
}

int lastNode(TreeNode* root) {

    if(root->left == NULL) return root->val;

    if(getHeight(root->left) > getHeight(root->right)) return lastNode(root->left);
    else return lastNode(root->right);
}
