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

#define ln ListNode*

class Solution {
public:
    ListNode* swapNodes(ListNode* h, int k) {
        
        
        int len = 0;
        
        ln nh = h;
        
        while(nh != NULL){
            ++len;
            nh = nh->next;
        }
        
        nh = h;
        
        int val1, val2;
        
        int cur = 0;
        
        
        while(nh != NULL){
            ++cur;
            if(cur == k) val1 = nh->val;
            if(cur == len-k+1) val2 = nh->val;
            nh = nh->next;
        }
        
        cur = 0;
        
        nh = h;
        
        while(nh != NULL){
            ++cur;
            if(cur == k) nh->val = val2;
            if(cur == len-k+1) nh->val = val1;
            
            nh = nh->next;
        }
        
        return h;
        
    }
};
