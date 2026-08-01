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
    void reverse(ListNode *head , int times){
        ListNode *prev = nullptr, *curr = head;
        while(times--){
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
    }
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *left = head, *right = head, *prevLeft = nullptr, *res = nullptr;
        while(left != nullptr){
            right = left->next;
            if(res == nullptr){
                res = right;
            }
            if(right == nullptr){
                break;
            }
            ListNode *nextLeft = right->next;
            reverse(left, 2);
            left->next = nextLeft;
            if(prevLeft){
                prevLeft ->next = right;
            }
            prevLeft = left;
            left = nextLeft;
        }
        return res;
    }
};