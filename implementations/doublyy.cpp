#include <iostream>
 using namespace std;
class DoublyLinkedList { private: struct Node { int data; Node* prev; Node* next;
        Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

Node* head;
Node* tail;


public: DoublyLinkedList() { head = nullptr; tail = nullptr; }

void push_back(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void push_front(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void pop_back() {
    if (tail == nullptr)
        return;

    Node* temp = tail;

    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }

    delete temp;
}

void pop_front() {
    if (head == nullptr)
        return;

    Node* temp = head;

    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }

    delete temp;
}

void display_forward() {
    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}

void display_backward() {
    Node* current = tail;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->prev;
    }

    cout << endl;
}

~DoublyLinkedList() {
    Node* current = head;

    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

};
int main() { DoublyLinkedList list;

    list.push_back(10);
list.push_back(20);
list.push_back(30);

list.display_forward();   // 10 20 30
list.display_backward();  // 30 20 10

list.push_front(5);
list.display_forward();   // 5 10 20 30

list.pop_back();
list.display_forward();   // 5 10 20

list.pop_front();
list.display_forward();   // 10 20

return 0; }