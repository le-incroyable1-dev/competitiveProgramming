//author : aurav
#include<bits/stdc++.h>
using namespace std;
#define tn TreeNode*

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


long coveredNodes(TreeNode* A) {

    queue<tn> q;
    q.push(A);
    vector<vector<int>> lvls;

    while(!q.empty()){
        int sz = q.size();
        vector<int> lvl;
        while(sz--){
            tn cur = q.front(); q.pop();
            lvl.push_back(cur->val);
            
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }

        lvls.push_back(lvl);
        lvl.clear();
        continue;
    }

    long cover = 0;
    long uncover = 0;
    for(auto lvl : lvls){
        for(int i = 0; i < lvl.size(); ++i){
            if(i == 0 || i == lvl.size() - 1) uncover += lvl[i];
            else cover += lvl[i];
        }
    }


    long dif = abs(cover - uncover);
    return dif;
}
