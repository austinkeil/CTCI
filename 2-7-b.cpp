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
    head = Insert(head, 21);
    head = Insert(head, 13);

    cout << "\nList 2:\n";
    Node* head2 = NewNode(3);
    head2 = Insert(head2, 1);
    head2 = Insert(head2, 3);
    temp->next = head2;
    head2 = temp;
    head2 = Insert(head2, 9);
    head2 = Insert(head2, 12);

    cout <<"\nList1: \n";
    Print(head);
    cout <<"\nList2: \n";
    Print(head2);

    Node* p1 = head;
    int n1 = 0;
    while (p1) {
        n1++;
        p1 = p1->next;
    }

    Node* p2 = head2;
    int n2 = 0;
    while (p2) {
        n2++;
        p2 = p2->next;
    }

    if (p1 != p2) {
        cout << "NO INTERSECTION!" << endl;
        return 0;
    }

    if (n1 > n2) {
        p1 = head;
        p2 = head2;
    } else {
        p1 = head2;
        p2 = head;
    }
    for (int i = 0; i < abs(n1-n2); i++) {
        p1 = p1->next;
    }
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }

    cout << "Intersection at: " << p1 << endl;
}