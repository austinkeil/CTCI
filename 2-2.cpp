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
    Node* kthToLast(int k);
    Node* kthToLastNoLength(int k);
    void print();
    void insert(int data);
};


SinglyLinkedList::SinglyLinkedList() {
    head = nullptr;
    length = 0;
}

Node* SinglyLinkedList::kthToLast(int k) {
    if (length <= k || k <= 0)
        return head;

    Node* cur = head;
    int i = 1;
    while (length - i > k) {
        cur = cur->next;
        i++;
    }
    return cur;
}

Node* SinglyLinkedList::kthToLastNoLength(int k) {
    if (k <= 0 || head == nullptr) {
        return head;
    }

    Node* cur = head;
    int i = 1;
    while (cur->next) {
        cur = cur->next;
        i++;
    }

    // i is now the length of the list

    cur = head;
    if (i - k < 0) {
        return cur;
    } else {
        int j = 1;
        while (j < i - k) {
            cur = cur->next;
            j++;
        }
        return cur;
    }

}

void SinglyLinkedList::print() {
    if (length == 0)
        return;
    Node* cur = head;
    while (cur) {
        cout << "i: " << cur->data << endl;
        cur = cur->next;
    }

}

void SinglyLinkedList::insert(int data) {
    Node* node = new Node();
    node->data = data;

    if (head == nullptr) {
        head = node;
    } else {
        node->next = head;
        head = node;
    }
    length++;
}

int main() {
    SinglyLinkedList* list1 = new SinglyLinkedList();
    for (int i = 0; i < 10; i++) {
        list1->insert(rand() % 100);
    }

    Node* p = list1->kthToLastNoLength(4);
    Node* q = list1->kthToLastNoLength(7);
    Node* r = list1->kthToLastNoLength(10);


    list1->print();
    cout << "List Length: " << list1->length << endl;

    cout << "\nTesting kthToLast(int k)" << endl;
    cout << "4th to last: " << p->data << endl;
    cout << "7th to last: " << q->data << endl;
    cout << "10th to last: " << r->data << endl;

}