#include <bits/stdc++.h>
using namespace std;
#define tn TreeNode*
#define ll long long

static auto _______ = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
}();


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    unordered_map<int, ll> level_sum;

    void fill_sum(TreeNode* cur, int d){

        if(cur == NULL) return;
        level_sum[d] += (ll)cur->val;

        fill_sum(cur->left, d+1);
        fill_sum(cur->right, d+1);
        return;
    }

    void change_tree(TreeNode* cur, int d){
        if(cur == NULL) return;

        ll l = 0;
        ll r = 0;

        if(cur->left != NULL) l = cur->left->val;
        if(cur->right != NULL) r = cur->right->val;

        ll d_sum = level_sum.find(d+1) != level_sum.end() ? level_sum[d+1] : 0;

        ll replace = d_sum - l - r;

        if(cur->left != NULL) cur->left->val = (int)replace;
        if(cur->right != NULL) cur->right->val = (int)replace;

        change_tree(cur->left, d+1);
        change_tree(cur->right, d+1);
        return;
    }
    

    TreeNode* replaceValueInTree(TreeNode* root) {
        fill_sum(root, 0);
        change_tree(root, 0);
        root->val = 0;

        return root;
    }
};
