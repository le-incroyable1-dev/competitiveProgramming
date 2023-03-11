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

class Solution {
public:
    ListNode *h = NULL;
    
    Solution(ListNode* head) {
        h = head;
    }
    
    int getRandom() {
        int ans = 0;
        int cur = 1;
        ListNode *p = h;
        while (p != NULL) {
            int x = rand(); cout << x << " " << cur << " ";
            if (x % cur == 0) ans = p->val;
            cout << ans << "\n";

            ++cur;
            p = p->next;
        }
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
