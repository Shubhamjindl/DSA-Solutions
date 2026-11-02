/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr) return nullptr;
        stack<Node*>st;
        Node* dummyHead = new Node(0);
        dummyHead->next = head;
        Node* newCurr = dummyHead;
        st.push(head);
        while(!st.empty()){
            Node* curr = st.top();
            newCurr->next = curr;
            newCurr->child = nullptr;
            curr->prev = newCurr;
            newCurr = st.top();
            st.pop();
            if(curr->next){
                st.push(curr->next);
            }
            if(curr->child){
                st.push(curr->child);
            }
        }
        Node* result = dummyHead->next;
        result->prev = nullptr;
        delete dummyHead;

        return result;
    }
};