/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count1 = 0, count2 = 0;
        ListNode* temp1 = headA, *temp2 = headB;
        while(temp1){
            count1++;
            temp1 = temp1->next;
        }
        while(temp2){
            count2++;
            temp2 = temp2->next;
        }
        int diff = abs(count1 - count2);
        temp1 = headA;
        temp2 = headB;
        for(int i = 1; i <= diff; i++){
            if(count1 > count2) temp1 = temp1->next;
            else if(count2 > count1) temp2 = temp2->next;
        }
        while(temp1 && temp2){
            if(temp1 == temp2){
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return nullptr;
    }
};