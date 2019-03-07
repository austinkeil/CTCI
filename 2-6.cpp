#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node *next;
    int data;
};

Node* newNode(int d) {
    Node* node = new Node();
    node->data = d;
    return node;
}

bool isPalindrome(Node* head) {
    Node* cur = head;
    vector<int> forward;
    stack<int> backward;
    while (cur) {
        forward.push_back(cur->data);
        backward.push(cur->data);
        cur = cur->next;
    }

    int j;
    for (int &i : forward) {
        j = backward.top();
        backward.pop();
        if (i != j) {
            return false;
        }
    }
    return true;
}

int main() {
    Node* node = newNode(1);
    struct Node* head2 = node;
    node->next = newNode(3);
    node = node->next;
    node->next = newNode(3);
    node = node->next;
    node->next = newNode(1);

    cout << isPalindrome(head2) << endl;
}