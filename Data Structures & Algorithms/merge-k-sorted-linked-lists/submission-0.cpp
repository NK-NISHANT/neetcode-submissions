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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);

        for(int i = 0; i < lists.size(); i++){
            if(lists[i] != NULL){
                pq.push(lists[i]);
            }
        }

        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();

            tail->next = temp;

            if(temp->next != NULL){
                pq.push(temp->next);
            }

            tail = tail->next;
        }

        return dummy->next;
    }
};
