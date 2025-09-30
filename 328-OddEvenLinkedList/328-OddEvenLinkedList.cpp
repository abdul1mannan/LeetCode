// Last updated: 10/1/2025, 12:48:50 AM
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL ||head->next==NULL){
            return head;
        }
        
        ListNode *odd =new ListNode(-1);
        
     ListNode *even =new ListNode(-1);
    
    ListNode*dummyodd=odd;
    ListNode*dummyeven=even;
        ListNode*curr=head;
        ListNode*temp;
        bool f=1;
    while(curr!= NULL){
        temp=curr;
        curr=curr->next;
        temp->next=NULL;
        if(f==0){
    
            even->next=temp;
            even=even->next;
            f=1;
        }
        else{
    
            odd->next=temp;
            f=0;
            odd=odd->next;
        }
      
    }
    odd->next=dummyeven->next;
    return dummyodd->next;
}
};