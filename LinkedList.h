#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

class LinkedList {
public:
    struct Node* head;
    struct Node* tail;
    int length;

    LinkedList();

    ~LinkedList();

    void appendToTail(int value);

    void print();

    void deleteNode(Node* node);
};

LinkedList::LinkedList() {
    this->length = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

LinkedList::~LinkedList() {
    Node* cur = head;
    Node* d = nullptr;
    while (cur) {
        d = cur;
        cur = cur->next;
        delete d;
    }
    cout << "LIST DELETED" << endl;
}

void LinkedList::appendToTail(int value) {
    Node* temp = new Node();
    temp->data = value;

    if (this->head == nullptr) {
        this->head = temp;
        this->tail = temp;
    } else {
        this->tail->next = temp;
        temp->prev = this->tail;
        this->tail = temp;
    }
    this->length++;
}

void LinkedList::print() {
    Node* temp = this->head;
    int i = 1;
    while (temp) {
        cout << i << ": " << temp->data << endl;
        temp = temp->next;
        i++;
    }
}

void LinkedList::deleteNode(Node* node) {

    if (this->length == 1) {
        this->head = nullptr;
        this->tail = nullptr;
    } else if (this->head == node) {
        this->head = node->next;
        node->next->prev = nullptr;
    } else if (this->tail == node) {
        this->tail = node->prev;
        node->prev->next = nullptr;
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    length--;
    delete node;
}