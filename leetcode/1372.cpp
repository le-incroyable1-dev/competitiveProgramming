#include <bits/stdc++.h>
using namespace std;
#define tn TreeNode*

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

    int max_len = 0;

    int path(tn cur, int dir){
        if(cur == NULL) return 0;

        int lp = path(cur->left, -1);
        int rp = path(cur->right, 1);

        int zigzag = 1;
        if(dir == 1) zigzag += lp;
        else if(dir == -1) zigzag += rp;

        int fresh = 0;
        fresh = max(lp, rp);

        max_len = max(max_len, fresh);
        max_len = max(max_len, zigzag);

        return zigzag;
    }

    int longestZigZag(TreeNode* root) {
        path(root->left, -1);
        path(root->right, 1); 
        return max_len;
    }
};
