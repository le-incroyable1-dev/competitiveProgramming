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
typedef TreeNode* tn;

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {

        bool res = true;
        queue<tn> q;
        q.push(root);

        bool stop = false;

        while(!q.empty()){
            int sz = q.size();
            
            for(int i = 0; i < sz; ++i){
                tn cur = q.front(); q.pop();

                if(stop && (cur->left || cur->right)) return false;

                if(cur->left) q.push(cur->left);
                else stop = true;

                if(stop && cur->right) return false;

                if(cur->right) q.push(cur->right);
                else stop = true;
                
            }
        }


        return res;

    }
};
