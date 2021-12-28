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
    ListNode* reverse(ListNode* head, int k) {
        ListNode* newHead = NULL;
        ListNode* ptr = head;
        while (k > 0) {
            ListNode* nextNode = ptr->next;
            ptr->next = newHead;
            newHead = ptr;
            ptr = nextNode;
            k--;
        }
        return newHead;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        ListNode* ktail = NULL;
        ListNode* newHead = NULL;
        
        while (ptr) {
            int count = 0;
            ptr = head;
            
            while (count < k && ptr) {
                ptr = ptr->next;
                count++;
            }
            
            if (count == k) {
                ListNode* revHead = reverse(head, k);
                if (!newHead) {
                    newHead = revHead;
                }
                if (ktail) {
                    ktail->next = revHead;
                }
                
                ktail = head;
                head = ptr;
            }
        }
        
        if (ktail) {
            ktail->next = head;
        }
        
        return !newHead ? head : newHead;
    }
};