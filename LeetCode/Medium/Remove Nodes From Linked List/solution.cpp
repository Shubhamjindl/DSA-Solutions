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
    ListNode* removeNodes(ListNode* head) {
        stack <ListNode*>st;
        ListNode* temp = head;
        while(temp != nullptr){
            while(!st.empty() && temp->val > st.top()->val){
                st.pop();
            }
            st.push(temp);
            temp = temp->next;
        }
        vector<ListNode*>v(st.size());
        int last = v.size()-1;
        while(!st.empty()){
            v[last] = st.top();
            last--;
            st.pop();
        }
        for(int i = 0; i < v.size() - 1; i++){
            v[i]->next = v[i+ 1];
        }
        v[v.size()-1]->next = nullptr;
        return v[0];
    }

};