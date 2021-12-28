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
        ListNode* dummy = new ListNode(0);
        ListNode* one = l1; ListNode* two = l2;
        ListNode* cur = dummy;
        int carry = 0;
        while (one || two) {
            int x = (one != nullptr) ? one->val : 0;
            int y = (two != nullptr) ? two->val : 0;
            int sum = x + y + carry;
            carry = sum/10;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            if (one != nullptr) one = one->next;
            if (two != nullptr) two = two->next;
        }
        if (carry > 0) {
            cur->next = new ListNode(carry);
        }
        return dummy->next;
    }
};