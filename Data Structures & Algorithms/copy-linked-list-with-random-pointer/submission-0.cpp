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
        Node* temp = head;

        //making copies in bw
        while(temp){
            Node* copy = new Node(temp->val);
            Node* next = temp->next;
            temp->next=copy;
            copy->next=next;
            temp=next;
        }

        temp=head;
        while(temp){
            Node* copy = temp->next;
            if(temp->random) copy->random = temp->random->next;
            temp=copy->next;
        }

        Node* dummy = new Node(-1);
        Node* res = dummy;
        temp=head;
        while(temp){
            Node* copy = temp->next;
            Node* next = copy->next;
            res->next = copy;
            res=res->next;
            temp->next=next;
            temp=temp->next;
        }
        return dummy->next;
    }
};
