/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 #include <bits/stdc++.h>
 using namespace std;

class Solution {
public:

    int res = INT_MIN;
    int maxNode = INT_MIN;

    int helper(TreeNode *root){

        if(root == NULL)
        return 0;

        maxNode = max(maxNode, root->val);

        int spl = helper(root->left);
        int spr = helper(root->right);

        int ret = max(spl+root->val, spr+root->val);
        ret = max(ret, root->val);
        res = max(res, max(ret, spl+root->val+spr));
        res = max(res, maxNode);
        return ret;

    }

    int maxPathSum(TreeNode* root) {

        int val = helper(root);
        int ans = res;

        return ans;
    }
};
