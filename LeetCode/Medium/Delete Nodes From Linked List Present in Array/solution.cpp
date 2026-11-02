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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>mySet;
        for(int i = 0; i < nums.size(); i++){
            mySet.insert(nums[i]);
        }
        if(head == nullptr) return nullptr;
        ListNode* dHead = new ListNode(0, head);
        ListNode* curr = dHead->next;
        ListNode* prev = dHead;
        while(curr){
            if(mySet.count(curr->val)){
                ListNode* del = curr;
                curr = curr->next;
                prev->next = nullptr;
            }
            else{
                prev->next = curr;
                prev = curr;
                curr = curr->next;
            }
        }
        return dHead->next;
    }
};