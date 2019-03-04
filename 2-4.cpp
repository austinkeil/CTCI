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

struct Node* partition(struct Node* head, int pivot) {
    struct Node *smallHead = nullptr, *smallTail = nullptr;
    struct Node *largeHead = nullptr, *largeTail = nullptr;

    while (head != nullptr) {
        if (head->data < pivot) {
            if (smallHead == nullptr) {
                smallHead = head;
                smallTail = head;
            } else {
                smallTail->next = head;
                smallTail = head;
            }
        } else {
            if (largeHead == nullptr) {
                largeHead = head;
                largeTail = head;
            } else {
                largeTail->next = head;
                largeTail = head;
            }
        }
        head = head->next;
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

int main() {
    Node* cur = newNode(rand() % 100);
    Node* head = cur;
    for (int i = 1; i < 10; i++) {
        Node* next = newNode(rand() % 100);
        cur->next = next;
        cur = next;
    }
    cout << "Before Partition: " << endl;
    print(head);
    head = partition(head, 50);
    cout << endl << "After Partition: " << endl;
    print(head);
}