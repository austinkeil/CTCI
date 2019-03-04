#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

Node* newNode(int data) {
    struct Node* node = new Node();
    node->data = data;
    node->next = nullptr;
    return node;
}

void print(Node* head) {
    int i = 1;
    while (head != nullptr) {
        cout << i << ": " << head->data << endl;
        head = head->next;
        i++;
    }
}

struct Node* partition(struct Node* node, int pivot) {
    struct Node *smallHead = nullptr, *smallTail = nullptr;
    struct Node *largeHead = nullptr, *largeTail = nullptr;

    while (node != nullptr) {
        if (node->data < pivot) {
            if (smallHead == nullptr) {
                smallHead = node;
                smallTail = node;
            } else {
                smallTail->next = node;
                smallTail = node;
            }
        } else {
            if (largeHead == nullptr) {
                largeHead = node;
                largeTail = node;
            } else {
                largeTail->next = node;
                largeTail = node;
            }
        }
        node = node->next;
    }

    if (smallHead == nullptr) {
        smallHead = largeHead;
    } else {
        smallTail->next = largeHead;
    }

    if (largeTail->next != nullptr) {
        largeTail->next = nullptr;
    }
    return smallHead;
}

struct Node* partition2(struct Node* head, int pivot) {
    struct Node* tail = head;

    Node* cur = head;
    while (cur != nullptr) {
        struct Node* next = cur->next;
        if (cur->data < pivot) {
            cur->next = head;
            head = cur;
        } else {
            tail->next = cur;
            tail = cur;
        }
        cur = next;
    }
    tail->next = nullptr;
    return head;
}

int main() {
    struct Node* cur = newNode(rand() % 100);
    struct Node* head = cur;
    for (int i = 1; i < 10; i++) {
        Node* next = newNode(rand() % 100);
        cur->next = next;
        cur = next;
    }
    cout << "Before Partition: " << endl;
    print(head);
    head = partition2(head, 50);
    cout << endl << "After Partition: " << endl;
    print(head);
}