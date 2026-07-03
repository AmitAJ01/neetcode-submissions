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

class compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        for(auto x: lists){
            if(x) pq.push(x);
        }

        while(!pq.empty()){
            ListNode* top = pq.top();
            pq.pop();
            temp->next = top;
            temp=temp->next;
            if(top->next) pq.push(top->next);
        }
        return dummy->next;
    }
};
