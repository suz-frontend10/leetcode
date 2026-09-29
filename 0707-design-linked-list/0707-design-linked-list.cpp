
class MyLinkedList {
private:
    struct Node {
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
    };

    Node* head;

public:
    MyLinkedList() {
        head = nullptr;
    }

    int get(int index) {
        Node* temp = head;

        for (int i = 0; i < index; i++) {
            if (temp == nullptr)
                return -1;
            temp = temp->next;
        }

        if (temp == nullptr)
            return -1;

        return temp->data;
    }

    void addAtHead(int val) {
        Node* newnode = new Node(val);
        newnode->next = head;
        head = newnode;
    }

    void addAtTail(int val) {
        Node* newnode = new Node(val);

        if (head == nullptr) {
            head = newnode;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    void addAtIndex(int index, int val) {
        if (index < 0)
            return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;

        for (int i = 0; i < index - 1; i++) {
            if (temp == nullptr)
                return;
            temp = temp->next;
        }

        if (temp == nullptr)
            return;

        Node* newnode = new Node(val);
        newnode->next = temp->next;
        temp->next = newnode;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || head == nullptr)
            return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;

        for (int i = 0; i < index - 1; i++) {
            if (temp == nullptr)
                return;
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr)
            return;

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
};