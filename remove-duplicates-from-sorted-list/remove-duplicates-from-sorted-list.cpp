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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==nullptr || head->next==nullptr) {
            return head;
        }
        ListNode* current = head->next;
        ListNode* prev = head;
        while (current!=nullptr) {
            if (prev->val == current->val) {
                prev->next = current->next;
            }
            else {
                prev = current;
            }
            current = current->next;
        }
        return head;
    }
};