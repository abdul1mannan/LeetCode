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
    ListNode* getNode(ListNode*temp,int k){
        k--;
        while(temp!=NULL &&k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto temp=head;
        ListNode* prevHead=NULL;
        while(temp!=NULL){
            ListNode *kNode=getNode(temp,k);
            if(kNode==NULL){
                if(prevHead){
                    prevHead->next=temp;
                }
                break;
            }
            ListNode* nextNode=kNode->next;
            kNode->next=NULL;
            reverseList(temp);
            if(temp==head){
                head=kNode;
            }
            else {
                prevHead->next=kNode;
            }
            prevHead=temp;
            temp=nextNode;
        }
        return head;
    }
};