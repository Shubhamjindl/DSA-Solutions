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
    void insertBegin(ListNode *begin, ListNode *head){
        ListNode *firstTemp = head;
        begin->next = firstTemp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *endNode = head;
        int size = 1;
        while(endNode->next != nullptr){
            endNode = endNode->next;
            size++;
        }
        k = k % size;
        int pivotpos = size - k;
        int place = 1;
        ListNode* pivotNode = head;
        while(place != pivotpos){
            pivotNode = pivotNode->next;
            place++;
        }
        insertBegin(endNode, head);
        head = pivotNode->next;
        pivotNode->next = nullptr;
        return head;
    }
};