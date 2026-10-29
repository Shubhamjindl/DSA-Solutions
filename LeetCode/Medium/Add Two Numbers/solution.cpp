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
        ListNode* dummyHead = new ListNode(0);
        ListNode* l3 = dummyHead;
        bool carry = false;
        while(l2 && l1){
            l3->next = l2;
            l3 = l2;
            int sum = l1->val + l2->val + carry;
            l3->val = sum % 10;
            carry = (sum > 9);
            l2 = l2->next;
            l1 = l1->next;
        }
        while(l2){
            l3->next = l2;
            l3 = l2;
            int sum = l2->val + carry;
            l3->val = sum % 10;
            carry = (sum > 9);
            l2 = l2->next;
        }
        while(l1){
            l3->next = l1;
            l3 = l1;
            int sum = l1->val + carry;
            l3->val = sum % 10;
            carry = (sum > 9);
            l1 = l1->next;
        }
        if (carry) {
            l3->next = new ListNode(1);
        }
        return dummyHead->next;
    }
};