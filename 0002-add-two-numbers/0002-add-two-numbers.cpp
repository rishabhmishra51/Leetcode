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
 ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = curr -> next;
        while(curr != NULL) {
                next = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = next;
        }
        return prev;
}
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
            if(head1 == NULL)
                return head2;
        if(head2 == NULL)
                return head1; 

        //step1 : reverse both linked list
        // head1 = reverse(head1);
        // head2 = reverse(head2);

        //step2: add both linked list
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        int carry = 0;

        while(head1 != NULL && head2 != NULL) {
                //calculate sum
                int sum = carry + head1 -> val + head2 -> val;
                //find digit to create node for
                int digit = sum % 10;
                //calculate carry
                carry = sum / 10;

                //create a new Node for the digit
                ListNode* newNode = new ListNode(digit);
                //attach the newNode into the answer wali linked list
                if(ansHead == NULL) {
                        //first node insert krre ho
                        ansHead = newNode;
                        ansTail = newNode;
                }
                else {
                        ansTail -> next = newNode;
                        ansTail = newNode;
                }
                head1 = head1 -> next;
                head2 = head2 -> next;
        }

        //jab head1 list ki length head2 list se jada hogi
        while(head1 != NULL) {
                int sum = carry + head1 -> val;
                int digit = sum % 10;
                carry = sum / 10;
                ListNode* newNode = new ListNode(digit);
                ansTail -> next = newNode;
                ansTail = newNode;
                head1 = head1 -> next;
        }

        //jab head2 list ki length head1 list se jada hogi
        while(head2 != NULL) {
                int sum = carry + head2 -> val;
                int digit = sum % 10;
                carry = sum / 10;
                ListNode* newNode = new ListNode(digit);
                ansTail -> next = newNode;
                ansTail = newNode;
                head2 = head2 -> next;
        }

        //handle carry ko alag se
        while(carry != 0) {
                int sum = carry;
                int digit = sum % 10;
                carry = sum / 10;
                ListNode* newNode = new ListNode(digit);
                ansTail -> next = newNode;
                ansTail = newNode;
        }


        //step3: reverse the ans linked list
        
        return ansHead;
    }
};