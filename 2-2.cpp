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
    Node* kthToLastNoLength2(int k);
    Node* kthToLastRecursive(Node* head, int k, int &i);
    Node* kthToLastRecursive(Node* head, int k);
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

// Implemented such that k=1 returns last element,
// k=2 returns second to last element
Node* SinglyLinkedList::kthToLastNoLength2(int k) {
    if (head == nullptr)
        return nullptr;

    Node* p1 = head;
    Node* p2 = head;

    for (int i = 0; i < k; i++) {
        if (p1 == nullptr)
            return nullptr;
        p1 = p1->next;
    }

    // now p1 is k elements ahead of p2

    while (p1) {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p2;
}

// Implemented such that k=1 returns last element,
// k=2 returns second to last element
Node* SinglyLinkedList::kthToLastRecursive(Node* head, int k, int &i) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* rn = kthToLastRecursive(head->next, k, i);
    i = i + 1;
    if (i == k) {
        return head;
    }
    return rn;
}

Node* SinglyLinkedList::kthToLastRecursive(Node* head, int k) {
    int i = 0;
    return kthToLastRecursive(head, k, i);
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


    Node* p = list1->kthToLastRecursive(list1->head, 4);
    Node* q = list1->kthToLastRecursive(list1->head, 7);
    Node* r = list1->kthToLastRecursive(list1->head, 10);


    list1->print();
    cout << "List Length: " << list1->length << endl;

    cout << "\nTesting kthToLast(int k)" << endl;
    cout << "4th to last: " << p->data << endl;
    cout << "7th to last: " << q->data << endl;
    cout << "10th to last: " << r->data << endl;

}