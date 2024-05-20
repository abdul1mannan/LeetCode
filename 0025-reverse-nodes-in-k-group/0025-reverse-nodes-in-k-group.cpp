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
   
    
    ListNode *reverseList(ListNode*temp){
        ListNode*dumb=temp;
        ListNode*prev=NULL;
        
        while(dumb!=NULL){
            ListNode* curr=dumb->next;
            dumb->next=prev;
            prev=dumb;
            dumb=curr;
        }
        return prev;
    }
    ListNode *getnode(ListNode*temp,int k){
        
        k--;
        while(temp!=NULL && k>0){
             k--;
            temp=temp->next;
           
        }
        return temp;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
       auto temp=head;
        ListNode*prev=NULL;
       while(temp!=NULL){
           ListNode *kNode=getnode(temp,k);
           if(kNode==NULL){
               if(prev){
                   prev->next=temp;
               }
               break;
           }
           ListNode*curr=kNode->next;
           kNode->next=NULL;
           reverseList(temp);
           if(temp==head){
               head=kNode;
           }
           else {
               prev->next=kNode;
               
           }
           prev=temp;
           temp=curr;
       }
        return head;
    }
};