class Node{
public:
    int val;
    Node* next;
    Node(){
        val = 0;
        next = nullptr;
    }
    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
};
class MyLinkedList {
    Node* head;
    Node* tail;
    int size;
public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    int get(int index) {
        if(index >= size){
            return -1;
        }
        Node* temp = head;
        int currIdx = 0;
        while(temp){
            if(currIdx == index){
                return temp->val;
            }
            temp= temp->next;
            currIdx++;
        }
        return -1;
    }
    void addAtHead(int val) {
        Node* n = new Node(val);
        if(head == nullptr){
            head = tail = n;
            size++;
            return;
        }
        n->next = head;
        head = n;
        size++;
    }
    void addAtTail(int val) {
        Node* n = new Node(val);
        if(head == nullptr){
            head = tail = n;
            size++;
            return;
        }
        tail->next = n;
        tail = n;
        size++;
    }
    void addAtIndex(int index, int val) {
        if(index > size){
            return;
        }
        if(index == 0){
            this->addAtHead(val);
            return;
        }
        if(index == size){
            this->addAtTail(val);
            return;
        }
        Node* temp = head;
        int currIdx = 0;
        while(temp){
            if(currIdx == index - 1){
                Node* n = new Node(val);
                Node* next = temp->next;
                temp->next = n;
                n->next = next;
                size++;
                return;
            }
            temp = temp->next;
            currIdx++;
        }
    }
    void deleteAtIndex(int index) {
        if(index >= size){
            return;
        }
        if(head == nullptr){
            return;
        }
        if(index == 0){
            Node* del = head;
            head = head->next;
            delete del;
            size--;
            if(head == nullptr){
                tail = nullptr;
            }
            return;
        }
        Node* temp = head;
        int currIdx = 0;
        while(temp){
            if(currIdx == index - 1){
                Node* del = temp->next;
                temp->next = temp->next->next;
                if(del == tail){
                    tail = temp;
                }
                delete del;
                size--;

                return;
            }
            temp = temp->next;
            currIdx++;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */