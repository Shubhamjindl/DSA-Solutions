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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* finalHead, *finall;
        if(list1 && list2){
            if(list1->val < list2->val){
                finalHead = list1;
                finall = list1;
                list1 = list1->next;
            }
            else{
                finalHead = list2;
                finall = list2;
                list2 = list2->next;
            }
        }
        else if(list1){
            finalHead = list1;
            finall = list1;
            list1 = list1->next;
        }
        else if(list2){
            finalHead = list2;
            finall = list2;
            list2 = list2->next;
        }
        else return nullptr;
        while(list1 && list2){
            if(list1->val < list2->val){
                finall->next = list1;
                finall = list1;
                list1 = list1->next;
            }
            else{
                finall->next = list2;
                finall = list2;
                list2 = list2->next;
            }
        }
        while(list1){
            finall->next = list1;
            finall = list1;
            list1 = list1->next;
        }
        while(list2){
            finall->next = list2;
            finall = list2;
            list2 = list2->next;
        }
        return finalHead;
    }
};