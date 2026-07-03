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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev=head;
            head=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* s = head;
        ListNode* f = head;
        while(f->next){
            f=f->next;
            if(f->next){
                f=f->next;
                s=s->next;
            }
        }
        ListNode* right = s->next;
        s->next=NULL;
        ListNode* left = head;
        right = reverse(right);
        
        while(left && right){
            ListNode* lnext = left->next;
            ListNode* rnext = right->next;

            left->next = right;
            right->next = lnext;
            
            left = lnext;
            right = rnext;
        }
    }
};