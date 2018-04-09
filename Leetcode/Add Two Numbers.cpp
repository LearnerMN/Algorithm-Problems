/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int t = 0;
        ListNode* tmp = result;
        while (t1 != NULL && t2 != NULL){
            int d = t1->val + t2->val + t;
            tmp->next = new ListNode(d % 10);
            t = d / 10;
            tmp = tmp->next;
            t1 = t1->next;
            t2 = t2->next;
        }
        
        while (t1 != NULL){
            int d = t1->val + t;
            tmp->next = new ListNode(d % 10);
            t = d / 10;
            tmp = tmp->next;
            t1 = t1->next;
        }
        
        while (t2 != NULL){
            int d = t2->val + t;
            tmp->next = new ListNode(d % 10);
            t = d / 10;
            tmp = tmp->next;
            t2 = t2->next;
        }
        
        if (t){
            tmp->next = new ListNode(1);
        }
        
        return result->next;
    }
};