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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        ListNode* temp = dummy;
        for(int i=1; i<left; i++) temp = temp->next;
        ListNode* start = temp->next;

        ListNode* rhead = temp->next;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        int k=right-left+1;
        while(k){
            next = rhead->next;
            rhead->next=prev;
            prev=rhead;
            rhead=next;
            k--;
        }
        temp->next=prev;
        start->next=rhead;
        
        return dummy->next;
    }
};