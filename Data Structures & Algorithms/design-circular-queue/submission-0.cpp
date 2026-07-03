class Node {
    public:
    int val;
    Node* prev;
    Node* next;
    Node(int val, Node* prev, Node* next){
        this->next = next;
        this->prev = prev;
        this->val = val;
    }
};
class MyCircularQueue {
public:
    int k;
    Node* left;
    Node* right;
    MyCircularQueue(int k) {
        this->k = k;
        left = new Node(-1, NULL, NULL);
        right = new Node(-1, left, NULL);
        left->next = right;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        Node* cur = new Node(value, right->prev, right);
        right->prev->next = cur;
        right->prev=cur;
        k--;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        left->next = left->next->next;
        left->next->prev = left;
        k++;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return left->next->val;
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return right->prev->val;
    }
    
    bool isEmpty() {
        return left->next==right;
    }
    
    bool isFull() {
        return k==0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */