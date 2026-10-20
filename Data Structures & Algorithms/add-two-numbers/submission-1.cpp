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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        
        int carry = 0;

        while(l1 != NULL || l2 != NULL){

            int d1 = 0;
            int d2 = 0;

            if(l1 != NULL){
                d1 = l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL){
                d2 = l2->val;
                l2 = l2->next;
            }

            int sum = d1+d2+carry;

            int result = sum%10;
            carry = sum/10;
            
            ListNode* newNode = new ListNode(result);

            if(head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        if (carry != 0){
            ListNode* newNode = new ListNode(carry);
            tail->next = newNode;
            tail = newNode;
        }

        return head;
    }
};
