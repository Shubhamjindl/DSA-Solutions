/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* n = new Node(data);
        if(head == nullptr){
            n->next = n;
            return n;
        }
        Node* curr = head;
        Node* prev = nullptr;
        do{
            prev = curr;
            curr = curr->next;
           if(curr->data >= n->data && n->data >= prev->data){
                prev->next = n;
                n->next = curr;
                return head;
            }
        } while(curr != head);
        if(n->data >= curr->data){
            prev->next = n;
            n->next = curr;
            return head;
        }
        else {
            prev->next = n;
            n->next = curr;
            head = n;
            return head;
        }
        
    }
};