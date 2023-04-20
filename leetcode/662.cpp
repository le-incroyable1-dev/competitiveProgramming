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
    int widthOfBinaryTree(TreeNode* root) {
        ll mx = 1;

        queue<pair<tn, ll>> q;
        q.emplace(root, 0);

        while(!q.empty()){

            ll s = q.front().second;
            ll e = q.back().second;

            mx = max(mx, e-s+1);

            ll sz = q.size();

            while(sz--){
                pair<tn, ll> p = q.front(); q.pop();

                tn cur = p.first;
                ll i = p.second - s;

                if(cur->left != NULL) q.emplace(cur->left, 2LL*i + 1LL);
                if(cur->right != NULL) q.emplace(cur->right, 2LL*i + 2LL);

                continue;
            }

            //cout << l << " " << r << "\n"
            continue;
        }

        return (int)mx;
    }
};
