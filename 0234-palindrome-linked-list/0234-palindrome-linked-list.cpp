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
    ListNode* reverseList(ListNode*node){
        auto temp=node;
        ListNode* prev=NULL;
        auto curr=temp;
        if(node==NULL ||node->next==NULL){
            return node;
        }
        while(temp!=NULL){
            temp=temp->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        auto slow=head;
        auto fast=head;
        if(head==NULL || head->next==NULL){
            return true;
        }
       while(fast->next!=NULL && fast->next->next!=NULL ){
            slow=slow->next;
            fast=fast->next->next;
        }
       ListNode* node=reverseList(slow->next);
       auto newHead=node;
       slow=head;
        while(node!=NULL){
            if(slow->val!=node->val){
                reverseList(newHead);
                return false;
            }
            slow=slow->next;
            node=node->next;
        }
        reverseList(newHead);
        return true;
        
    }
};