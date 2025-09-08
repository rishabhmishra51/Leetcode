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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) return {-1, -1};

        ListNode* prev = head;
        ListNode* temp = prev->next;
        ListNode* front = temp->next;

        int index = 1;
        int first = -1, last = -1;
        int minDist = INT_MAX;

        while (front) {
            // Check if temp is a critical point
            if ((temp->val > prev->val && temp->val > front->val) ||
                (temp->val < prev->val && temp->val < front->val)) {

                if (first == -1) {
                    first = index;
                } else {
                    minDist = min(minDist, index - last);
                }
                last = index;
            }

            prev = temp;
            temp = front;
            front = front->next;
            index++;
        }

        if (first == -1 || first == last) return {-1, -1};
        return {minDist, last - first};
    }
};
