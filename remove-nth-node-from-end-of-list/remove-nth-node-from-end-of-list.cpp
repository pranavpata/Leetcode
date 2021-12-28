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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next) return nullptr; 
        ListNode* end = head;
        ListNode* cur = nullptr;
        for (int i = 0; i < n; i++) {
            end = end->next;
        }
        while (end) {
            end = end->next;
            if (!cur)
                cur = head;
            else
                cur = cur->next;
        }
        if (!cur) {
            head = head->next;
        }
        else
            cur->next = cur->next->next;
        
        return head;
    }
};