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
    ListNode *reversell(ListNode *head){
        
        if(head==NULL ||head->next==NULL){
            return head;
        }
        
        ListNode*newhead=reversell(head->next);
        ListNode *front=head->next;
        front->next=head;
        head->next=NULL;
        
        return newhead;
    }
    
    ListNode *findkth(ListNode *head,int k){
        
        k--;
        while(head!=NULL && k>0){
            k--;
            head=head->next;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *temp=head;
        ListNode *prev=NULL;
        while(temp!=NULL){
        ListNode *kthnode=findkth(temp,k);
        if(kthnode==NULL){
            if(prev){
                prev->next=temp;
            }
            break;
        }
            ListNode *coming=kthnode->next;
            kthnode->next=NULL;
             reversell(temp);
            if(temp==head){
                head=kthnode;
            }
            else {
                prev->next=kthnode;
        }
        prev=temp;
        temp=coming;
        }
        return head;
    }
};