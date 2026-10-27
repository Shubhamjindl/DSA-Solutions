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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;
        for(int i = 1; i <= n; i++){
            curr = curr->next;
        }
        ListNode* prev = dummy;
        while(curr->next != nullptr){
            curr = curr->next;
            prev = prev->next;
        }
        ListNode* del = prev->next;
        prev->next = del->next;
        delete del;
        return dummy->next;
    }
};