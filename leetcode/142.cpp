/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;
typedef ListNode* ln;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head == NULL || head->next == NULL) return NULL;

        ln s = head->next;
        ln f = head->next->next;
        int k = 0;

        while(s != f){
            if(s == NULL || f == NULL) return NULL;

            s = s->next;
            

            if(f->next == NULL) return NULL;
            f = f->next->next;

            ++k;
        }

        //cout << s->val << "\n";

        int x = 0;

        while(head != s) head = head->next, s = s->next, ++x;

        //cout << k << " " << x << "\n";

        return s;
    }
};
