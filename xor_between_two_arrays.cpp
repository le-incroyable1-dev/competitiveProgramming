#include <bits/stdc++.h>
using namespace std;


class TrieNode{

public:

    TrieNode* l;
    TrieNode *r;

    bool end;

    TrieNode(){
        l = NULL;
        r = NULL;
       end = false;
    }


};

void insert(TrieNode *t, int num){
    TrieNode *root = t;
    for(int i = 0; i <= 31; ++i){
        if(((1<<i)&num) > 0){
            if(root->r != NULL) root = root->r;
            else{
                root->r = new TrieNode();
                root = root->r;
            }
        }
        else{
            if(root->l != NULL) root = root->l;
            else{
                root->l = new TrieNode();
                root = root->l;
            }
        }
    }
}

int xor_val(TrieNode *t, int num){

    TrieNode *root = t;
    int val = 0;
    for(int i = 0; i <= 31; ++i){
        int x = num;
        if((x&(1<<i)) > 0){
            if(root->l != NULL) val += (1<<i), root = root->l;
            else root = root->r;
        }
        else{
            if(root->r != NULL) val += (1<<i), root = root->r;
            else root = root->l;
        }
    }

    return val;
}

int Solution::solve(vector<int> &a, vector<int> &b) {

    TrieNode *root = new TrieNode();
    int res = 0;
    for(auto x : a) insert(root, x);
    for(auto x : b) res = max(res, xor_val(root, x));

    return res;
}
