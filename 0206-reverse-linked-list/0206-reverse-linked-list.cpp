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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL ||head->next==NULL){
            return head;
        }
        
        ListNode*newnode=reverseList(head->next);
        ListNode*start=head->next;
        start->next=head;
        head->next=NULL;
        
        return newnode;
//         ListNode*temp=head;
//         ListNode*prev=NULL;
        
//         while(temp!=NULL){
//             ListNode*start=temp->next;
//             temp->next=prev;
//             prev=temp;
//             temp=start;
//         }
//         return prev;
    }
};