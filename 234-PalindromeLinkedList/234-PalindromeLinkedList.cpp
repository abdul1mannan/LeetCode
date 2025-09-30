// Last updated: 10/1/2025, 12:49:07 AM
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
    
    ListNode *reversell(ListNode*head){
        
        if(head==NULL || head->next==NULL){
            return head;
        }
    ListNode *temp=reversell(head->next);
      ListNode *front=head->next;
        front->next=head;
        head->next=NULL;
        return temp;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        
        }
        ListNode*temp=slow->next;
        ListNode *newnode=reversell(temp);
        ListNode*tem=newnode;
        ListNode*first=head;
        while(tem!=NULL){
            
           if(first->val!=tem->val){
               reversell(newnode);
                return false;
            }
             first=first->next;
                tem=tem->next;
        }
        reversell(newnode);
        return true;
    
    }
};