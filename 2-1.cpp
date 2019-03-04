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

    void printReversed();

    void deleteDups();
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

void LinkedList::printReversed() {
    Node* temp = this->tail;
    int i = this->length;
    while (temp) {
        cout << i << ": " << temp->data << endl;
        temp = temp->prev;
        i--;
    }
}

void LinkedList::deleteDups() {
    Node* cur = this->head;
    Node* d = nullptr;

    unordered_set<int> seen;
    while(cur) {
        if (seen.count(cur->data)) {
            if (cur->next) {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
            } else {
                cur->prev->next = nullptr;
            }
            d = cur;
            cur = cur->next;
            this->length--;
            delete d;
        } else {
            seen.insert(cur->data);
            cur = cur->next;
        }
    }
}

int main() {
    LinkedList* list1 = new LinkedList();
    for (int i = 0; i < 10; i++) {
        list1->appendToTail(rand() % 5);
    }

    list1->print();
    cout << "List Length: " << list1->length << endl;

    list1->deleteDups();
    list1->print();
    cout << "List Length: " << list1->length << endl;

    delete list1;
    return 0;
}