class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Dummy node to handle edge cases where head needs to be deleted
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* current = head;
        
        while (current != nullptr) {
            if (current->val == val) {
                prev->next = current->next;
                delete current;  // Free memory
            } else {
                prev = current;
            }
            current = prev->next;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};
