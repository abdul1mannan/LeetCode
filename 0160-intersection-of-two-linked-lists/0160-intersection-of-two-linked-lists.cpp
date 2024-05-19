/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto temp=headA;
        auto temp2=headB;
        while(temp!=temp2){
            if(temp==NULL){
                temp=headB;
            }
         else  temp=temp->next;
            if(temp2==NULL){
                temp2=headA;
            }
           
            else temp2=temp2->next;
        }
        return temp;
    }
};