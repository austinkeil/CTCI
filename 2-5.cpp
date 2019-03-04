#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
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

int sum(struct Node* head1, struct Node* head2, int subSum, int multiplier) {
    if (head1 == nullptr && head2 == nullptr) {
        return subSum;
    } else if (head1 == nullptr) {
        return subSum + sum(nullptr, head2->next, subSum, multiplier*10) + head2->data*multiplier;
    } else if (head2 == nullptr) {
        return subSum + sum(head1->next, nullptr, subSum, multiplier*10) + head1->data*multiplier;
    } else {
        return subSum + sum(head1->next, head2->next, subSum, multiplier*10) + head1->data * multiplier + head2->data * multiplier;
    }
}

int sum(struct Node* head1, struct Node* head2) {
    int subSum = 0, multiplier = 1;
    return sum(head1, head2, subSum, multiplier);
}

Node* sum2(struct Node* head1, struct Node* head2, int carry) {
    if (head1 == nullptr && head2 == nullptr && carry == 0) {
        return nullptr;
    }

    Node* result = new Node();
    int value = carry;
    if (head1 != nullptr) {
        value += head1->data;
    }

    if (head2 != nullptr) {
        value += head2->data;
    }

    result->data = value % 10;

    if (head1 != nullptr || head2 != nullptr) {
        Node* more = sum2(head1 == nullptr ? nullptr : head1->next, head2 == nullptr ? nullptr : head2->next, value >= 10 ? 1 : 0);
        result->next = more;
    }
    return result;
}

int main() {
    struct Node* node = newNode(1);
    struct Node* head1 = node;
    node->next = newNode(5);
    node = node->next;
    node->next = newNode(9);

    node = newNode(2);
    struct Node* head2 = node;
    node->next = newNode(3);
    node = node->next;
    node->next = newNode(6);
    node = node->next;
    node->next = newNode(7);


    cout << "Sum: " << endl;
    cout << sum(head1, head2) << endl;
    Node* head = sum2(head1, head2, 0);
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
}