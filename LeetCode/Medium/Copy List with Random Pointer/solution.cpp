/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        unordered_map<Node*,Node*>mp;
        Node* newList = nullptr, *newCurr = nullptr;
        if(curr){
            Node* n = new Node(curr->val);
            mp.insert({curr, n});
            newCurr = n;
            newList = n;
            if(curr->random){
                if(mp.find(curr->random) == mp.end()){
                    Node *n = new Node(curr->random->val);
                    newCurr->random = n;
                    mp.insert({curr->random, n});
                }
                else newCurr->random = mp[curr->random];
            }
            else newCurr->random = nullptr;
            curr = curr->next;
        }
        while(curr){
            if(mp.find(curr) == mp.end()){
                Node* n = new Node(curr->val);
                mp.insert({curr, n});
                newCurr->next = n;
                newCurr = newCurr->next;
            }
            else{
                newCurr->next = mp[curr];
                newCurr = newCurr->next;
            }
            if(curr->random){
                if(mp.find(curr->random) == mp.end()){
                    Node* n = new Node(curr->random->val);
                    newCurr->random = n;
                    mp.insert({curr->random, n});
                }
                else newCurr->random = mp[curr->random];
            }
            else newCurr->random = nullptr;
            curr = curr->next;
        }
        return newList;
    }
};