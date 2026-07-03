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
    int len(ListNode* head){
        ListNode* temp=head;
        int len=0;
        while(temp){
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int l = len(head);
        if(!head || !head->next || k>l) return head;

        ListNode* curr = head;
        ListNode* nxt = NULL;
        ListNode* prv = NULL;
        int pos=0;
        while(pos<k){
            pos++;
            nxt = curr->next;
            curr->next=prv;
            prv=curr;
            curr=nxt;
        }
        if(nxt){
            ListNode* recAns = reverseKGroup(nxt, k);
            head->next = recAns;
        }
        return prv;
    }
};
