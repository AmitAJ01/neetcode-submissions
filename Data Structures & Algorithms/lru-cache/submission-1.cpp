class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int val, Node* prev, Node* next, int key){
        this->val = val;
        this->prev = prev;
        this->next = next;
        this->key=key;
    }
};

class LRUCache {
public:
    Node* start;
    Node* end;
    int size;
    unordered_map<int, Node*> m;
    LRUCache(int capacity) {
        start = new Node(-1, NULL, NULL,-1);
        end = new Node(-1, start, NULL,-1);
        start->next = end;
        size=capacity;
    }
    
    void deleteNode(Node* node){
        Node* nxt = node->next;
        Node* prv = node->prev;

        nxt->prev = prv;
        prv->next = nxt;

    }

    void insert(Node* node){
        Node* first = start->next;
        start->next = node;
        node->prev = start;
        node->next = first;
        first->prev = node;
    }
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        Node* cur = m[key];
        deleteNode(cur);
        insert(cur);
        return cur->val;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* cur = m[key];
            cur->val = value;
            deleteNode(cur);
            insert(cur);
        }
        else{
            if(m.size()==size){
                Node* last = end->prev;
                deleteNode(last);
                m.erase(last->key);
            }
            Node* node = new Node(value,NULL,NULL,key);
            m[key] = node;
            insert(node);
        }
    }
};
