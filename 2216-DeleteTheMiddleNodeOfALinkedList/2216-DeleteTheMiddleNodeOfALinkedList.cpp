// Last updated: 10/1/2025, 12:47:04 AM
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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL ||head->next==NULL){
            return NULL;
        }
      ListNode *slow=head;
        ListNode* fast=head;
        fast=head->next->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*temp=slow->next;
        slow->next=slow->next->next;
        temp->next=NULL;
        return head;
    
    }
};