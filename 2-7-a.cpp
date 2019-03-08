#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* NewNode(int data) {
    Node* n = new Node();
    n->data = data;
    n->next = nullptr;
    return n;
}

Node* Insert(Node* head, int data) {
    Node* temp = NewNode(data);
    if (head == nullptr) {
        return temp;
    }
    temp->next = head;
    return temp;
}

void Print(Node* head) {
    while(head) {
        cout << head->data << " at " << head << endl;
        head = head->next;
    }
}

int main() {
    cout << "List 1: \n";
    Node* head = NewNode(5);
    head = Insert(head, 10);
    Node* temp = Insert(head, 17);
    head = temp;
    head = Insert(head, 7);
    head = Insert(head, 2);
    head = Insert(head, 13);
    Print(head);
    cout << "Address of temp: " << temp << endl;

    cout << "\nList 2:\n";
    Node* head2 = NewNode(3);
    head2 = Insert(head2, 1);
    head2 = Insert(head2, 3);
    temp->next = head2;
    head2 = temp;
    head2 = Insert(head2, 7);
    head2 = Insert(head2, 12);
    Print(head2);

    Node* intersecting;

    Node* p1 = head;
    unordered_multiset<Node*> set1;
    while (p1) {
        set1.insert(p1);
        p1 = p1->next;
    }
    Node* p2 = head2;
    while (p2) {
        if (set1.count(p2) > 0) {
            intersecting = p2;
            break;
        }
        p2 = p2->next;
    }

    cout << "\nList 1 v2:\n";
    Print(head);

    cout << "\nList 2 v2:\n";
    Print(head2);

    cout << "Address of temp: " << temp << endl;
    cout << "Address of intersecting node: " << intersecting << endl;
}