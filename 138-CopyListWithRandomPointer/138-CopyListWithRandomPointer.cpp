// Last updated: 10/1/2025, 12:49:54 AM
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
    
    void insertnode(Node *head){
        Node *temp=head;
        while(temp!=NULL){
            Node *node=temp->next;
            Node *copy=new Node(temp->val);
            copy->next=node;
            temp->next=copy;
            temp=node;
        }
    }
    
    void connectrandom(Node *head){
        Node *temp=head;
        while(temp!=NULL){
            Node *node=temp->next;
            if(temp->random){
                node->random=temp->random->next;
                
            }
            else{
                node->random=NULL;
            }
            temp=temp->next->next;
        }
    }
    Node* copy(Node *head){
        Node *temp=head;
        Node *dummy=new Node(-1);
    Node *res=dummy;
        
        while(temp!=NULL){
            res->next=temp->next;
            res=res->next;
            
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummy->next;
    
    }
    
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        
        insertnode(head);
        connectrandom(head);
        return copy(head);
    }
};