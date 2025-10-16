class MyLinkedList {
private:
    struct Node{
        int val;
        Node* next;
        Node(int val){
            this->val=val;
            this->next=NULL;
        }
    };
    Node* head;
    int size;
public:
    MyLinkedList() {
        size=0;
        head=NULL;
    }
    int get(int index) {
        if(index>=size || index<0) return -1;
        Node* temp=head;
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        size++;
    }
    
    void addAtTail(int val) {
        Node* node = new Node(val);
        if (!head) {
            head = node;
        } else {
            Node* curr = head;
            while (curr->next)
                curr = curr->next;
            curr->next = node;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size) return;
        if(index==0) addAtHead(val);
        else if(index==size) addAtTail(val);
        else{
            Node* temp=new Node(val);
            Node* curr=head;
            for(int i=0;i<index-1;i++){
                curr=curr->next;
            }
            temp->next=curr->next;
            curr->next=temp;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* prev = head;
            for (int i = 0; i < index - 1; i++)
                prev = prev->next;

            Node* toDelete = prev->next;
            prev->next = prev->next->next;
            delete toDelete;
        }
        size--;
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