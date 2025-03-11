class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
       ListNode* slow=head;
       ListNode* fast = head;
        while(slow!=NULL && fast!= NULL){
            fast = fast->next;
            if( fast != NULL){
                slow=slow->next;
                fast=fast->next;
            }
        }
        return slow;
    }
};