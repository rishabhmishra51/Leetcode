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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
         ListNode* fast=head;

         while(fast&&fast->next){
            fast=fast->next;
            if(fast!=NULL){
                 fast=fast->next;
                 slow=slow->next;
            }
           
         }
      
            ListNode* prev=NULL;
            ListNode* curr=slow;
            while(curr){
                ListNode* forward = curr->next;
                curr->next = prev;
                prev=curr;
                curr=forward;
            }
         
        ListNode* first = head;
        ListNode* second = prev; 
        while (second) { 
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;
    }
};