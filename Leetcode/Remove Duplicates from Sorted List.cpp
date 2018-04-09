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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;
            
        ListNode* prev = head;
        ListNode* current = head->next;
        
        while (current != NULL){
            if (prev->val == current->val){
                if (current->next != NULL){
                    current->val = current->next->val;
                    current->next = current->next->next;    
                }else{
                    prev->next = NULL;
                    current = NULL;
                }
                
            }else{
                prev = current;
                current = current->next;
            }
        }
        
        
        return head;
    }
};