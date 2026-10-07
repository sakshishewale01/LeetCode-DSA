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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // STEP 1: Dummy node to make building the answer easy
        ListNode* dummy = new ListNode(0);

        // STEP 2: temp points to the last node of answer
        ListNode* temp = dummy;

        // STEP 3: Carry from previous addition
        int carry = 0;

        // STEP 4: Continue while there is something to process
        while(l1 != nullptr || l2 != nullptr || carry != 0) {

            // STEP 5: Get digits
            int x = 0;
            int y = 0;

            if(l1 != nullptr)
                x = l1->val;

            if(l2 != nullptr)
                y = l2->val;

            // STEP 6: Add the two digits + carry
            int sum = x + y + carry;

            // STEP 7: Current digit
            int digit = sum % 10;

            // STEP 8: New carry
            carry = sum / 10;

            // STEP 9: Create new node
            temp->next = new ListNode(digit);

            // Move temp
            temp = temp->next;

            // STEP 10: Move input lists
            if(l1 != nullptr)
                l1 = l1->next;

            if(l2 != nullptr)
                l2 = l2->next;
        }

        // STEP 11: Return actual answer
        return dummy->next;
    }
};