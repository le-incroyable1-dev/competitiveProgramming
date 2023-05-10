#include <bits/stdc++.h>
using namespace std;
#define ln ListNode*

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:
    
    void mark(int &mx, ln node){
        if(node == NULL) return;
        
        mark(mx, node->next);
        if(mx > node->val) node->val = -1;
        else mx = max(mx, node->val);
        
        return;
    }
    
    ListNode* removeNodes(ListNode* h) {
        
        if(h->next == NULL) return h;
        
        ln h1 = h;
        int mx = 0;
        mark(mx, h1);
        
        
        ln res = NULL;
        
        while(h != NULL && h->val == -1) h = h->next;
        
        res = h;
        ln ans = res;
        h = h->next;
        
        while(1){
            while(h != NULL && h->val == -1) h = h->next;
            if(h == NULL) break;
            res->next = h; res = res->next;
            h = h->next;
        }
        
        return ans;
    }
};
