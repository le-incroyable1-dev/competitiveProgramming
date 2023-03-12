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

#include <bits/stdc++.h>
using namespace std;
typedef ListNode* ln;

class comp {
    public:
        bool operator() (const ListNode* a, const ListNode* b) {
            return (a->val > b->val);
    }
};

class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& v) {

        priority_queue<ln, vector<ln>, comp> pq;

        for(auto l : v){
            if(l != NULL) pq.push(l);
        }

        ln ans = NULL;
        ln head = NULL;
        ln cur = NULL;
        
        while(!pq.empty()){
            cur = pq.top(); pq.pop();
            //cout << cur->val << "\n";
            if(cur->next != NULL) pq.push(cur->next);

            if(ans == NULL){
                ans = cur;
                head = cur;
            }
            else{
                head->next = cur;
                head = head->next;
            } 
        }

        
        return ans;
    }
};
