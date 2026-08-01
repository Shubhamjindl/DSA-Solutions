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
    void reverse(ListNode *head, int times){
            ListNode *prev = nullptr, *curr = head;
            while(times--){
                ListNode *nextTemp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextTemp; 
            }
        }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *left = head, *right, *res = nullptr, *prevLeft = nullptr;
        int size = k;
        while(true){
            right = left;
            for(int i = 0; i < size - 1; i++){
                if(right == nullptr){
                    break;
                }
                right = right ->next;
            }
            if(right){
                ListNode *nextLeft = right->next;
                reverse(left, size);
                if(prevLeft){
                    prevLeft->next = right;
                }
                if(res == nullptr){
                    res = right;
                }
                prevLeft = left;
                left = nextLeft;
            }
            else{ // if right == null
                prevLeft->next = left;
                if(res == nullptr){
                    res = left;
                }
                break;
            }
        }
        return res;
    }
};