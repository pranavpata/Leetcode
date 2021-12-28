/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        unordered_map<Node*,Node*>mp;
        Node* newHead=NULL,*newtail=NULL;
        Node* curr=head;
        while(curr)
        {
             Node* temp=new Node(curr->val);
             
             if(newHead==NULL)
             {
                 newHead=temp;
                 newtail=temp;
             }
             else
             {
                newtail->next=temp;
                newtail=newtail->next;
             }
             mp[curr]=temp;
             curr=curr->next;
        }
        Node* temp=head;
        curr=newHead;
        while(curr)
        {
             Node* nxtrand=mp[temp->random];
             curr->random=nxtrand;
             curr=curr->next;
             temp=temp->next;
       }
        return newHead;
    }
};