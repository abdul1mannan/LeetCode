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
        bool f=1;
    while(head!= NULL){
        if(f==0){
            ListNode *temp=new ListNode(head->val);
            even->next=temp;
            even=even->next;
            f=1;
        }
        else{
             ListNode *temp=new ListNode(head->val);
            odd->next=temp;
            f=0;
            odd=odd->next;
        }
        head=head->next;
    }
    odd->next=dummyeven->next;
    return dummyodd->next;
}
};