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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL||k==0){
            return  head;
        }
        
        auto temp=head;
int count=1;
        while(temp->next!=NULL){
            temp=temp->next;
                count++;
        }
        temp->next=head;
        auto curr=head;
        k=k%count;
        int end=count-k;
        while(--end){
            curr=curr->next;
        }
        head=curr->next;
        curr->next=NULL;
        return head;
    }
};