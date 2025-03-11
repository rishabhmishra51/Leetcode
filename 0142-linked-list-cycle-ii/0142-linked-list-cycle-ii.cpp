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
    ListNode *detectCycle(ListNode *head) {
        
    
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast != NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(fast==slow){
            
            break;
        }

    }
    if(fast==slow){
            slow=head;
           
        }
        else return NULL;
    while(fast !=slow){
         fast=fast->next;
            slow=slow->next;
    }
    return slow;
    }

};