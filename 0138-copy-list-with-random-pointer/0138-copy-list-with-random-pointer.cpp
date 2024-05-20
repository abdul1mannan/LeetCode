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
        map<Node*,Node*>c;
        auto temp=head;
    
        while(temp!=NULL){
          Node *newNode=new Node(temp->val);
            c[temp]=newNode;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            Node *copy=c[temp];
            copy->next=c[temp->next];
            copy->random=c[temp->random];
            temp=temp->next;
        }
        return c[head];
    }
};