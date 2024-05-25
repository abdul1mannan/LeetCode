class LRUCache {
public:
    
    class node{
        public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int key1,int val1){
            key=key1;
            val=val1;
            
        }
    };
    
    node *head=new node(-1,-1);
    node *tail=new node(-1,-1);
    
    unordered_map<int,node*>m;
    int size;
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addnode(node *newnode){
        node *temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
     void deletenode(node * delnode) {
    node * delprev = delnode -> prev;
    node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }
    int get(int key) {
        if(m.find(key)!=m.end()){
            node *resused=m[key];
            m.erase(key);
            int res=resused->val;
            deletenode(resused);
            addnode(resused);
            m[key]=head->next;
            return res;
            
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node *existnode=m[key];
            m.erase(key);
            deletenode(existnode);
        }
        if(m.size()==size){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */