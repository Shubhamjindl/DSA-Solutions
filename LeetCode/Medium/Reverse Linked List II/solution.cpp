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
        ListNode* dummy = new ListNode(0, head);
        ListNode* temp = dummy;
        int place = 0;
        while(place < left -1){
            temp = temp->next;
            place++;
        }
        ListNode *stPartNode = temp;
        ListNode *endPartNode = temp->next;
        ListNode *prev = temp->next;
        ListNode *curr = temp->next->next;
        place += 2;
        ListNode *nextTemp;
        while(place < right + 1){
            nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
            place++;
        }
        endPartNode->next = curr;
        stPartNode->next = prev;
        return dummy->next;
    }
};