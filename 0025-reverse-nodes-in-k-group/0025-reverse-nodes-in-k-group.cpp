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
    int getlength(ListNode* head){
        ListNode* temp =head;
        int c=0;
        while(temp){
            c++;
            temp=temp->next;
        }   
        return c;
    }
    ListNode* reverseKNode(ListNode* head, int k){
        int len = getlength(head);
        if(k>len) return head;
        ListNode* prev= NULL;
        ListNode* curr = head;
        int count=0;
        while(count<k){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev =curr;
            curr=forward;
            count++;
           
        }
         
         if(curr != NULL){
            head->next = reverseKNode(curr, k);
        }
      return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseKNode(head,k);
    }
};