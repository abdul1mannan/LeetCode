/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // map<Node*,Node*>c;
        auto temp=head;
     if(head==NULL){
         return NULL;
     }
        
        while(temp!=NULL){
            Node *newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=NULL){
            Node*copy=temp->next;
            if(temp->random==NULL){
                copy->random=NULL;
            }
            else {
            copy->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        temp=head;
        Node *dummy=new Node(-1);
        auto curr=dummy;
        while(temp!=NULL){
            dummy->next=temp->next;
            temp->next=temp->next->next;
            temp=temp->next;
           dummy=dummy->next;
        }
        return curr->next;
        // while(temp!=NULL){
        //   Node *newNode=new Node(temp->val);
        //     c[temp]=newNode;
        //     temp=temp->next;
        // }
        // temp=head;
        // while(temp!=NULL){
        //     Node *copy=c[temp];
        //     copy->next=c[temp->next];
        //     copy->random=c[temp->random];
        //     temp=temp->next;
        // }
        // return c[head];
    }
};