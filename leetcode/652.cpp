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
#define tn TreeNode*

class Solution {

private:

    unordered_map<string, tn> m;
    unordered_set<tn> s;
    
    string helper(tn root){
        if(root == NULL) return "";

        string cur = "";

        string left = helper(root->left);
        if(left != "") left += "-";
        string right = helper(root->right);
        if(right != "") right += "-";

        cur += left;
        cur += to_string(root->val);
        cur += right;

        if(m.find(cur) != m.end()){
            s.insert(m[cur]);
        }
        else m[cur] = root;

        return cur;
    }


public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string str = helper(root);
        vector<tn> ans;

        for(auto node : s) ans.push_back(node);
        return ans;
    }
};
