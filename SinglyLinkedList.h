#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
public:
    Node* head;
    int length;
    SinglyLinkedList();
    void print();
    Node* insert(int data);
};


SinglyLinkedList::SinglyLinkedList() {
    head = nullptr;
    length = 0;
}

void SinglyLinkedList::print() {
    if (length == 0)
        return;
    Node* cur = head;
    int i = 1;
    while (cur) {
        cout << i << ": " << cur->data << endl;
        cur = cur->next;
        i++;
    }

}

Node* SinglyLinkedList::insert(int data) {
    Node* node = new Node();
    node->data = data;

    if (head == nullptr) {
        head = node;
    } else {
        node->next = head;
        head = node;
    }
    length++;
    return node;
}
